/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:47:06 by fhongu            #+#    #+#             */
/*   Updated: 2023/03/15 22:20:57 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				ncopy;

	if ((dst == 0 && src == 0) || n == 0)
		return (dst);
	if (dst > src)
	{
		d = dst + n - 1;
		s = src;
		while (n--)
			*(d--) = *(s + n);
	}
	else
	{
		d = dst;
		s = src;
		ncopy = n - 1;
		while (n--)
			*(d++) = *(s + (ncopy - n));
	}
	return (dst);
}
