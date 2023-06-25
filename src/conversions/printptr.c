/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:03:25 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/24 18:25:40 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printptr(int *counter, t_bflags bflags, size_t ptr)
{
	char	*str;
	char	*addr_char;

	str = ft_calloc(1, sizeof (char));
	while (ptr >= 0)
	{
		addr_char = ft_calloc(2, sizeof (char));
		addr_char[0] = digit(ptr, 16);
		str = ft_preppend(str, addr_char);
		ptr /= 16;
		free(addr_char);
		if (!ptr)
			break ;
	}
	str = ft_preppend(str, "0x");
	printstr(counter, bflags, str);
	free(str);
}
