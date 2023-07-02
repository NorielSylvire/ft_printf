/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:44:20 by fhongu            #+#    #+#             */
/*   Updated: 2023/03/17 20:09:55 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			str1;
	size_t			str2;
	size_t			i;

	str1 = (unsigned long) s1;
	str2 = (unsigned long) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i++ < n)
	{
		if (*(unsigned char *)str1++ != *(unsigned char *)str2++)
			return ((int)(*(unsigned char *)--str1 - *(unsigned char *)--str2));
	}
	return (0);
}
