/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:03:25 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/27 22:20:33 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	printptr(char **str, t_flags flags, size_t ptr)
{
	char	*p_str;
	char	*addr_char;

	p_str = ft_calloc(1, sizeof (char));
	while (ptr >= 0)
	{
		addr_char = ft_calloc(2, sizeof (char));
		if (!addr_char)
			return ;
		addr_char[0] = digit(ptr, 16);
		p_str = ft_preppend(p_str, addr_char, 1, 1);
		ptr /= 16;
		if (!ptr)
			break ;
	}
	p_str = ft_preppend(p_str, "0x", 1, 0);
	printstr(str, flags, p_str);
	ft_free((void **) &p_str);
}
