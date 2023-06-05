/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:53:49 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/05 21:00:21 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	printnum(int *counter, t_bflags bflags, int num)
{
	char	*str;

	str = ft_itoa(num);
	printstr(counter, bflags, str);
}
