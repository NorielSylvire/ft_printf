/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:32:07 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/27 22:13:30 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printstr(char **str, t_flags flags, char *arg)
{
	if (!arg)
	{
		ft_free((void **) &arg);
		arg = "(null)";
	}
	if (BONUS)
	{
		printstr_bonus(str, flags, arg);
	}
	else
	{
		*str = ft_append(*str, arg, 1, 0);
	}
}
