/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:34:33 by fhongu            #+#    #+#             */
/*   Updated: 2023/03/17 19:41:50 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	size_t			str;
	size_t			i;

	ch = (unsigned char) c;
	str = (unsigned long) s;
	i = 0;
	while (i++ < n)
	{
		if (*(unsigned char *)str++ == ch)
			return ((void *)--str);
	}
	return (NULL);
}
