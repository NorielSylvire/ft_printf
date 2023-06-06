/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:53:49 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/06 20:55:46 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	printnum(int *counter, t_bflags bflags, int num)
{
	char	*str;
	long	n;
	int		bigger;
	int		len;
	int		neg;

	n = (long) num;
	neg = 0;
	if (n < 0 || bflags.plus)
	{
		if (n < 0)
		{
			neg = 1;
			n *= -1;
		}
		bflags.min_width--;
	}
	else if (bflags.plus)
	str = ft_itoa(n);
	len = (int) ft_strlen(str);
	bigger = len;
	if (bflags.precision > len)
		bigger = bflags.precision;
	if (!bflags.minus)
	{
		while (bflags.min_width-- > bigger)
			*counter += ft_putchar_fd(' ', 1);
		if (neg)
			*counter += ft_putchar_ft('-', 1);
		else if (bflags.plus)
			*counter += ft_putchar_fd('+', 1);
		while (bflags.precision-- > len)
			*counter += ft_putchar_fd('0', 1);
		*counter += ft_putstr_fd(str, 1);
	}
}
