/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_formatting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:08:15 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/27 22:18:18 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static char	*prefix(char *str, int num, int base, int uppercase);

char	*format_base(char *str, t_flags flags)
{
	char	*pre;
	int		len;
	int		i;

	if (flags.dot && flags.precision == 0 && *str == '0')
		*str = '\0';
	len = (int) ft_strlen(str);
	if (flags.precision - len > 0)
	{
		pre = ft_calloc(flags.precision - len + 1, sizeof (char));
		i = 0;
		while (flags.precision-- > len)
			pre[i++] = '0';
		str = ft_preppend(str, pre, 1, 1);
	}
	return (str);
}

char	*width_and_sign_base(char *str, t_flags flags, int num, int base)
{
	int	len;

	len = (int) ft_strlen(str);
	if (flags.plus || (flags.blank && (flags.zero || flags.minus)))
		flags.min_width--;
	if (flags.hash && num != 0)
	{
		if (base == 8)
			flags.min_width--;
		else if (base == 16)
			flags.min_width -= 2;
	}
	if (flags.zero && !flags.minus && !flags.dot)
		str = width(str, &flags, len, '0');
	if (flags.plus)
		str = ft_preppend(str, "+", 1, 0);
	if (flags.hash && (*str != '0' || flags.precision <= len))
		str = prefix(str, num, base, flags.uppercase);
	str = width(str, &flags, len, ' ');
	return (str);
}

char	*space_base(char *str, t_flags flags, long num)
{
	if ((flags.blank && !flags.plus && num >= 0)
		&& (*str != ' ' || (*str == ' ' && flags.zero)))
		str = ft_preppend(str, " ", 1, 0);
	if (num == 0 && flags.minus && flags.blank
		&& flags.dot && flags.precision == 0 && flags.min_width > 1)
		str = ft_preppend(str, " ", 1, 0);
	return (str);
}

static char	*prefix(char *str, int num, int base, int uppercase)
{
	if (num == 0)
		return (str);
	else if (base == 16)
	{
		str = ft_preppend(str, "0x", 1, 0);
		if (uppercase)
			str[1] = 'X';
	}
	else if (base == 8)
		str = ft_preppend(str, "0", 1, 0);
	return (str);
}
