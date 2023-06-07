/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:32:07 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/06 23:11:22 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printstr(int *counter, t_bflags bflags, char *str)
{
	bflags.min_width -= (int) ft_strlen(str);
	if (bflags.minus)
	{
		*counter += ft_putstr_fd(str, 1);
		while (bflags.min_width-- > 0)
			*counter += ft_putchar_fd(' ', 1);
	}
	else
	{
		while (bflags.min_width-- > 0)
			*counter += ft_putchar_fd(' ', 1);
		*counter += ft_putstr_fd(str, 1);
	}
}
