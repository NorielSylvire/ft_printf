/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:17 by fhongu            #+#    #+#             */
/*   Updated: 2023/03/17 19:38:20 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;

	i = 0;
	while (*s1 && *s2 && i < n)
	{
		if (*s1 != *s2)
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		i++;
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	if (i == n)
		return (*--s1 - *--s2);
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
