/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:30:42 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/06 23:11:11 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printchar(int *counter, t_bflags bflags, int ch)
{
	if (bflags.minus)
	{
		*counter += ft_putchar_fd(ch, 1);
		while (--bflags.min_width > 0)
			*counter += ft_putchar_fd(' ', 1);
	}
	else
	{
		while (--bflags.min_width > 0)
			*counter += ft_putchar_fd(' ', 1);
		*counter += ft_putchar_fd(ch, 1);
	}
}
