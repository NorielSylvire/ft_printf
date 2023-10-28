/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:53:49 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/27 22:31:25 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printnum(char **str, t_flags flags, int num)
{
	long	n;

	n = (long) num;
	if (n < 0)
		n *= -1;
	ft_free((void **) str);
	*str = ft_ltoa(n);
	if (BONUS)
	{
		format_number(flags, str);
		*str = width_and_sign(*str, flags, n);
		*str = space(*str, flags, n);
	}
	else if (num < 0)
	{
		*str = ft_preppend(*str, "-", 1, 0);
	}
}
