/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:53:49 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/05 22:19:23 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	printnum(int *counter, t_bflags bflags, int num)
{
	char	*str;
	int		bigger;
	int		len;
	int		neg;

	neg = 0;
	if (num < 0)
	{
		neg = 1;
		num *= -1;
	}
	str = ft_itoa(num);
	len = (int) ft_strlen(str);
	bigger = len;
	if (bflags.precision > len)
		bigger = bflags.precision;
	bflags.min_width -= neg;
	if (!bflags.minus)
	{
		while (bflags.min_width-- > bigger)
			*counter += ft_putchar_fd(' ', 1);
		if (neg)
			*counter += ft_putchar_ft('-', 1);
		while (bflags.precision-- > len)
			*counter += ft_putchar_fd('0', 1);
		*counter += ft_putstr_fd(str, 1);
	}
}
