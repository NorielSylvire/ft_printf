/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:31:42 by fhongu            #+#    #+#             */
/*   Updated: 2023/07/02 20:24:23 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	init_bflags(t_bflags *bflags);
static int	parse_str(const char *str, size_t *i, t_bflags *bf, va_list args);
static void	parse_bonus(const char *str, size_t *i, t_bflags *blfags);
static void	parse_conv(const char ch, int *ctr, t_bflags bflags, va_list args);

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_bflags	bonus_flags;
	int			ctr;
	size_t		i;

	va_start(args, str);
	ctr = 0;
	i = 0;
	while (str[i])
	{
		init_bflags(&bonus_flags);
		if (str[i] == '%' && str[i + 1])
			ctr += parse_str(str, &i, &bonus_flags, args);
		else
			printchar(&ctr, bonus_flags, str[i]);
		i++;
	}
	va_end(args);
	return (ctr);
}

static int	parse_str(const char *str, size_t *i, t_bflags *bf, va_list args)
{
	int			ctr;
	size_t		i_percent;

	ctr = 0;
	i_percent = *i;
	*i += 1;
	if (ft_strchr("-.# +", str[*i]) || ft_isdigit(str[*i]))
		parse_bonus(str, i, bf);
	if (ft_strchr("cspdiuxX%o", str[*i]) && !bf->invalid)
		parse_conv(str[*i], &ctr, *bf, args);
	else
		ctr += ft_putsubstr_fd(str, i_percent, *i, 1);
	return (ctr);
}

static void	init_bflags(t_bflags *bflags)
{
	bflags->invalid = 0;
	bflags->perc = 0;
	bflags->minus = 0;
	bflags->zero = 0;
	bflags->dot = 0;
	bflags->hash = 0;
	bflags->blank = 0;
	bflags->plus = 0;
	bflags->width_parsed = 0;
	bflags->min_width = 0;
	bflags->precision = 0;
}

static void	parse_bonus(const char *str, size_t *i, t_bflags *bflags)
{
	while (ft_strchr("-.# +", str[*i]) || ft_isdigit(str[*i]))
	{
		if (str[*i] == '-' && !bflags->width_parsed)
			bflags->minus = 1;
		else if (str[*i] == '0' && !bflags->zero && !bflags->width_parsed)
			bflags->zero = 1;
		else if (ft_isdigit(str[*i]) && !bflags->width_parsed && str[*i != '0'])
			parse_width(str, i, bflags);
		else if (str[*i] == '.' && !bflags->dot)
			parse_precision(str, i, bflags);
		else if (str[*i] == '#' && !bflags->hash && !bflags->width_parsed)
			bflags->hash = 1;
		else if (str[*i] == ' ' && !bflags->blank && !bflags->width_parsed)
			bflags->blank = 1;
		else if (str[*i] == '+' && !bflags->plus && !bflags->width_parsed)
			bflags->plus = 1;
		else
		{
			bflags->invalid = 1;
			break ;
		}
		if (!bflags->width_parsed && !bflags->dot)
			*i += 1;
	}
}

static void	parse_conv(const char ch, int *ctr, t_bflags bflags, va_list args)
{
	if (ch == 'd' || ch == 'i')
		printnum(ctr, bflags, va_arg(args, int));
	else if (ch == 'c')
		printchar(ctr, bflags, va_arg(args, int));
	else if (ch == '%')
		printchar(ctr, bflags, '%');
	else if (ch == 's')
		printstr(ctr, bflags, va_arg(args, char *));
	else if (ch == 'p')
		printptr(ctr, bflags, va_arg(args, size_t));
	else if (ch == 'o')
		printbase(ctr, bflags, va_arg(args, unsigned int), 8);
	else if (ch == 'u')
		printbase(ctr, bflags, va_arg(args, unsigned int), 10);
	else if (ch == 'x' || ch == 'X')
	{
		if (ch == 'X')
			bflags.uppercase = 1;
		printbase(ctr, bflags, va_arg(args, unsigned int), 16);
	}
}
