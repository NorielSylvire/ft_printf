/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:53:49 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/15 19:02:32 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printnum(int *counter, t_bflags bflags, int num)
{
	long	n;
	char	*str;

	n = (long) num;
	str = format_number(bflags, n);
	str = width_and_sign(str, bflags, n);
	str = space(str, bflags, n);
	*counter += ft_putstr_fd(str, 1);
	ft_free((void **) &str);
}
