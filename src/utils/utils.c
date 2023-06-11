/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:20:58 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/11 17:33:37 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void parse_nbr(const char *str, size_t *i, t_bflags *bflags)
{
	bflags->width_parsed = 1;
	while (ft_isdigit(str[*i]))
	{
		bflags->min_width += str[*i] - '0';
		if (ft_isdigit(str[*i + 1]))
			bflags->min_width *= 10;
		*i += 1;
	}
}
