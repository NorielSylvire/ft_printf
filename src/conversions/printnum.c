/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:53:49 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/11 19:17:59 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printnum(int *counter, t_bflags bflags, int num)
{
	char	*str;
	char	*filler;
	long	n;
	int		neg;

	filler = ft_calloc(2, sizeof (char));
	*filler = ' ';
	if (bflags.zero && !bflags.minus)
		*filler = '0';
	n = (long) num;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	str = ft_itoa(n);
	if (neg || bflags.plus || bflags.blank)
		bflags.min_width--;
	while (bflags.min_width--)
	{
		if (bflags.minus)
			str = ft_append(str, filler);
		else
			str = ft_preppend(str, filler);
	}
	if (neg)
		str = ft_preppend(str, "-");
	else if (bflags.plus)
		str = ft_preppend(str, "+");
	else if (bflags.blank)
		str = ft_preppend(str, " ");
	*counter += ft_putstr_fd(str, 1);
}
