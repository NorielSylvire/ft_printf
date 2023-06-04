/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:30:42 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/04 21:36:27 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void printchar(int *counter, t_bflags bflags, int ch)
{
	*counter += ft_putchar_fd(ch, 1);
}
