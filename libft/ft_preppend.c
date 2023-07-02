/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preppend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:57:57 by fhongu            #+#    #+#             */
/*   Updated: 2023/07/02 20:14:07 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_preppend(const char *str, const char *pre)
{
	size_t	strlen;
	size_t	total_len;
	char	*result;

	strlen = ft_strlen(str);
	total_len = strlen + ft_strlen(pre);
	result = ft_calloc(total_len + 1, sizeof (char));
	while (*pre)
		*result++ = *pre++;
	while (*str)
		*result++ = *str++;
	free((void *) str - strlen);
	return (result - total_len);
}
