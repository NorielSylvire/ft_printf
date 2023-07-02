/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:37:35 by fhongu            #+#    #+#             */
/*   Updated: 2023/07/02 19:40:40 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*format_number(t_bflags bflags, long num)
{
	char	*ret;
	char	*pre;
	int		len;
	int		i;

	if (num < 0)
		num *= -1;
	ret = ft_ltoa(num);
	if (bflags.dot && bflags.precision == 0 && *ret == '0')
		*ret = '\0';
	len = (int) ft_strlen(ret);
	if (bflags.precision - len > 0)
	{
		pre = ft_calloc(bflags.precision - len + 1, sizeof (char));
		i = 0;
		while (bflags.precision-- > len)
			pre[i++] = '0';
		ret = ft_preppend(ret, pre);
		ft_free(&pre);
	}
	return (ret);
}

char	*width_and_sign(char *str, t_bflags bflags, long num)
{
	int	len;

	len = (int) ft_strlen(str);
	if (bflags.plus || num < 0
		|| (bflags.blank && (bflags.zero || bflags.minus)))
		bflags.min_width--;
	if (bflags.zero && !bflags.minus && !bflags.dot)
		str = width(str, &bflags, len, '0');
	if (num < 0)
		str = ft_preppend(str, "-");
	else if (bflags.plus)
		str = ft_preppend(str, "+");
	str = width(str, &bflags, len, ' ');
	return (str);
}

char	*space(char *str, t_bflags bflags, long num)
{
	if ((bflags.blank && !bflags.plus && num >= 0)
		&& (*str != ' ' || (*str == ' ' && bflags.zero)))
		str = ft_preppend(str, " ");
	if (num == 0 && bflags.minus && bflags.blank
		&& bflags.dot && bflags.precision == 0 && bflags.min_width > 1)
		str = ft_preppend(str, " ");
	return (str);
}

char	*width(char *str, t_bflags *bflags, int len, char filler)
{
	char	*pre;
	int		i;

	if (bflags->min_width > len)
	{
		pre = ft_calloc(bflags->min_width - len + 1, sizeof (char));
		i = 0;
		while (bflags->min_width-- > len)
			pre[i++] = filler;
		if (bflags->minus)
			str = ft_append(str, pre);
		else
			str = ft_preppend(str, pre);
		ft_free(&pre);
	}
	return (str);
}
