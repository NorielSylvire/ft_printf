/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:14:51 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/27 22:47:07 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printchar_bonus(char **str, t_flags flags, char *apd)
{
	if (flags.minus)
	{
			*str = ft_append(*str, apd, 1, 1);
		while (--flags.min_width > 0)
			*str = ft_append(*str, " ", 1, 0);
	}
	else
	{
		while (--flags.min_width > 0)
			*str = ft_append(*str, " ", 1, 0);
		*str = ft_append(*str, apd, 1, 1);
	}
}
