/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:31:42 by fhongu            #+#    #+#             */
/*   Updated: 2023/11/07 18:30:29 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*parse_str(const char *str, size_t *i, t_flags *fl, va_list args);
static void	parse_conv(const char ch, char **p_str, t_flags fl, va_list args);
static void	init_flags(t_flags *flags);

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_flags		flags;
	char		*f_str;
	size_t		i;
	int			ret;

	va_start(args, str);
	f_str = ft_calloc(1, sizeof (char));
	i = 0;
	while (str[i])
	{
		init_flags(&flags);
		if (str[i] == '%' && str[i + 1])
			f_str = ft_append(f_str, parse_str(str, &i, &flags, args), 1, 1);
		else
			printchar(&f_str, flags, str[i]);
		i++;
	}
	ft_putstr_fd(f_str, 1);
	ret = (int) ft_strlen(f_str);
	ft_free((void **) &f_str);
	va_end(args);
	return (ret);
}

static void	init_flags(t_flags *flags)
{
	flags->invalid = 0;
	flags->perc = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->blank = 0;
	flags->plus = 0;
	flags->uppercase = 0;
	flags->width_parsed = 0;
	flags->min_width = 0;
	flags->precision = 0;
}

static char	*parse_str(const char *str, size_t *i, t_flags *fl, va_list args)
{
	char		*parsed_str;
	size_t		i_percent;

	parsed_str = ft_calloc(1, sizeof (char));
	i_percent = *i;
	*i += 1;
	if (BONUS && (ft_strchr("-.# +", str[*i]) || ft_isdigit(str[*i])))
		parse_bonus(str, i, fl);
	if (ft_strchr("cspdiuxX%o", str[*i]) && !fl->invalid)
		parse_conv(str[*i], &parsed_str, *fl, args);
	else
		parsed_str = ft_substr(str, i_percent, *i - i_percent - 1);
	return (parsed_str);
}

static void	parse_conv(const char ch, char **p_str, t_flags fl, va_list args)
{
	if (ch == 'd' || ch == 'i')
		printnum(p_str, fl, va_arg(args, int));
	else if (ch == 'c')
		printchar(p_str, fl, va_arg(args, int));
	else if (ch == '%')
		printchar(p_str, fl, '%');
	else if (ch == 's')
		printstr(p_str, fl, va_arg(args, char *));
	else if (ch == 'p')
		printptr(p_str, fl, va_arg(args, size_t));
	else if (ch == 'u')
		printbase(p_str, fl, va_arg(args, unsigned int), 10);
	else if (ch == 'x' || ch == 'X')
	{
		if (ch == 'X')
			fl.uppercase = 1;
		printbase(p_str, fl, va_arg(args, unsigned int), 16);
	}
}
