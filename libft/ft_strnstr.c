/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:25:40 by fhongu            #+#    #+#             */
/*   Updated: 2023/04/09 22:51:04 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_loop(size_t i, size_t len, const char *needle);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	unsigned long	hs;
	char			*found;
	const char		*nd;

	i = 0;
	hs = (unsigned long) haystack;
	if (*needle == '\0' || haystack == needle)
		return ((char *) hs);
	if (*haystack == 0)
		return (NULL);
	while (*(char *)hs != '\0' && ft_loop(i++, len, needle))
	{
		nd = needle;
		found = (char *) hs;
		while (*nd++ == *found++)
			if (*nd == '\0')
				return ((char *) hs);
		hs++;
	}
	return (NULL);
}

static int	ft_loop(size_t i, size_t len, const char *needle)
{
	if (len == (size_t) -1)
		return (1);
	if (len < ft_strlen(needle))
		return (0);
	if (i < len - ft_strlen(needle) + 1)
		return (1);
	return (0);
}
