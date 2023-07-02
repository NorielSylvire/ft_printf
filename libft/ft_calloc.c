/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:43:31 by fhongu            #+#    #+#             */
/*   Updated: 2023/03/26 19:03:36 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*retbuff;
	void	*retcopy;
	size_t	i;

	retbuff = malloc(count * size);
	if (!retbuff)
		return (NULL);
	retcopy = retbuff;
	i = 0;
	while (i++ < count * size)
	{
		*(unsigned char *) retcopy++ = 0;
	}
	return (retbuff);
}
