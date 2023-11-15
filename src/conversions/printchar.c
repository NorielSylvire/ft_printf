/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:30:42 by fhongu            #+#    #+#             */
/*   Updated: 2023/11/15 09:18:46 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printchar(char **str, t_flags *flags, int ch)
{
	char	*apd;

	if (!ch)
		flags->nullChars++;
	apd = ft_calloc(2, sizeof (char));
	*apd = (char) ch;
	if (BONUS)
	{
		printchar_bonus(str, *flags, apd);
	}
	else
	{
		*str = ft_append(*str, apd, 1, 1);
	}
}
