/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:31:42 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/05 20:55:04 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			ctr += parse_str(str, &i, &bonus_flags, args);
		}
		else
			printchar(&ctr, bonus_flags, str[i]);
		i++;
	}
	va_end(args);
	return (ctr);
}

static int	parse_str(const char *str, size_t *i, t_bflags bf, va_list args)
{
	int			ctr;
	size_t		i_percent;

	init_bflags(bf);
	ctr = 0;
	i_percent = *i++;
	if (ft_strchr("-.# +", str[*i + 1]) || ft_isdigit(str[*i + 1]))
		parse_bonus(str, i, bf);
	if (ft_strchr("cspdiuxX", str[*i]) && !bf->invalid)
		parse_conversion(str[*i], &ctr, *bf, args);
	else
		print_invalid(str, i_percent, i);
	return (ctr);
}

static void	init_bflags(t_bflags *bflags)
{
	bflags->width_parsed = 0;
	bflags->perc = 0;
	bflags->minus = 0;
	bflags->zero = 0;
	bflags->dot = 0;
	bflags->hash = 0;
	bflags->blank = 0;
	bflags->plus = 0;
	bflags->min_width = 0;
	bflags->invalid = 0;
}

static void	parse_bonus(const char *str, size_t *i, t_bflags *bflags)
{
	while (ft_strchr("-.# +", str[*i]) || ft_isdigit(str[*i]))
	{
		if (str[*i] == '-' && !bflags->minus)
			bflags->minus = 1;
		else if (str[*i] == '.' && !bflags->dot)
			bflags->dot = 1;
		else if (str[*i] == '#' && !bflags->hash)
			bflags->hash = 1;
		else if (str[*i] == ' ' && !bflags->blank)
			bflags->blank = 1;
		else if (str[*i] == '+' && !bflags->plus)
			bflags->plus = 1;
		else
		{
			bflags->invalid = 1;
			break ;
		}
		*i += 1;
	}
}

static void	parse_conv(const char ch, int *ctr, t_bflags bflags, va_list args)
{
	if (ch == 'd' || ch == 'i')
		printnum(ctr, bflags, va_arg(args, int));
	else if (ch == 'c')
		printchar(ctr, bflags, va_arg(args, int));
	else if (ch == 's')
		printstr(ctr, bflags, va_arg(args, char *));
	else if (ch == 'p')
		printptr(ctr, bflags, va_arg(args, size_t));
	else if (ch == 'u')
		printuns(ctr, bflags, va_arg(args, unsigned int));
	else if (ch == 'x' || ch == 'X')
		printbase(ch, ctr, bflags, va_arg(args, unsigned int), 16, "");
}
