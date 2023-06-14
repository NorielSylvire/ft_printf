/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:03:25 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/14 23:16:51 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printptr(int *counter, t_bflags bflags, size_t ptr)
{
	char	*str;
	char	*addr_char;

	str = ft_calloc(3, sizeof (char));
	str[0] = '0';
	str[1] = 'x';
	while (ptr >= 16)
	{
		addr_char = ft_calloc(2, sizeof (char));
		addr_char[0] = digit(ptr, 16);
		ft_preppend(str, addr_char);
		ptr /= 16;
	}
	printstr(counter, bflags, str);
}
