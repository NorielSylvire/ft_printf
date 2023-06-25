/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_formatting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:08:15 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/25 22:00:29 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static char	*prefix(char *str, t_bflags *bflags, int num, int base);

char  *format_base(char *str, t_bflags bflags)
{
	char  *pre;
	int	  len;
	int	  i;

	if (bflags.dot && bflags.precision == 0 && *str == '0')
		*str = '\0';
	len = (int) ft_strlen(str);
	if (bflags.precision - len > 0)
	{
		pre = ft_calloc(bflags.precision - len + 1, sizeof (char));
		i = 0;
		while (bflags.precision-- > len)
			pre[i++] = '0';
		str = ft_preppend(str, pre);
		ft_free(&pre);
	}
	return (str);
}

char  *width_and_sign_base(char *str, t_bflags bflags, int num, int base)
{
	int	len;

	len = (int) ft_strlen(str);
	if (bflags.plus || (bflags.blank && (bflags.zero || bflags.minus)))
		bflags.min_width--;
	if (bflags.zero && !bflags.minus && !bflags.dot)
		str = width(str, &bflags, len, '0');
	if (bflags.plus)
		str = ft_preppend(str, "+");
	if (bflags.hash && (*str != '0' || bflags.precision <= len))
		str = prefix(str, &bflags, num, base);
	str = width(str, &bflags, len, ' ');
	return (str);
}

char  *space_base(char *str, t_bflags bflags, long num)
{
	if ((bflags.blank && !bflags.plus && num >= 0) 
		&& (*str != ' ' || (*str == ' ' && bflags.zero)))
		str = ft_preppend(str, " ");
	if (num == 0 && bflags.minus && bflags.blank 
		&& bflags.dot && bflags.precision == 0 && bflags.min_width > 1)
		str = ft_preppend(str, " ");
	return (str);
}

static char	*prefix(char *str, t_bflags *bflags, int num, int base)
{
	if (num == 0)
		return (str);
	else if (base == 16)
	{
		str = ft_preppend(str, "0x");
		bflags->min_width -= 2;
	}
	else if (base == 8)
	{
		str = ft_preppend(str, "0");
		bflags->min_width -= 2;
	}
	return (str);
}
