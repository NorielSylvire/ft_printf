/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:37:35 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/28 10:28:09 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	format_number(t_flags flags, char **str)
{
	char	*pre;
	int		len;
	int		i;

	if (flags.dot && flags.precision == 0 && **str == '0')
		**str = '\0';
	len = (int) ft_strlen(*str);
	if (flags.precision - len > 0)
	{
		pre = ft_calloc(flags.precision - len + 1, sizeof (char));
		i = 0;
		while (flags.precision-- > len)
			pre[i++] = '0';
		*str = ft_preppend(*str, pre, 1, 1);
	}
}

char	*width_and_sign(char *str, t_flags flags, int negative)
{
	int	len;

	len = (int) ft_strlen(str);
	if (flags.plus || negative
		|| (flags.blank && (flags.zero || flags.minus)))
		flags.min_width--;
	if (flags.zero && !flags.minus && !flags.dot)
		str = width(str, &flags, len, '0');
	if (negative)
		str = ft_preppend(str, "-", 1, 0);
	else if (flags.plus)
		str = ft_preppend(str, "+", 1, 0);
	str = width(str, &flags, len, ' ');
	return (str);
}

char	*space(char *str, t_flags flags, long num)
{
	if ((flags.blank && !flags.plus && num >= 0)
		&& (*str != ' ' || (*str == ' ' && flags.zero)))
		str = ft_preppend(str, " ", 1, 0);
	if (num == 0 && flags.minus && flags.blank
		&& flags.dot && flags.precision == 0 && flags.min_width > 1)
		str = ft_preppend(str, " ", 1, 0);
	return (str);
}

char	*width(char *str, t_flags *flags, int len, char filler)
{
	char	*pre;
	int		i;

	if (flags->min_width > len)
	{
		pre = ft_calloc(flags->min_width - len + 1, sizeof (char));
		i = 0;
		while (flags->min_width-- > len)
			pre[i++] = filler;
		if (flags->minus)
			str = ft_append(str, pre, 1, 1);
		else
			str = ft_preppend(str, pre, 1, 1);
	}
	return (str);
}
