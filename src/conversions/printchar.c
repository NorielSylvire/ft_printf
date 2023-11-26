/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:30:42 by fhongu            #+#    #+#             */
/*   Updated: 2023/11/25 21:46:15 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printchar(char **str, t_flags *flags, int ch)
{
	char	*apd;

	if ((ch % 256) == 0)
		flags->null_chars++;
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
