/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:23:49 by fhongu            #+#    #+#             */
/*   Updated: 2023/04/09 22:49:23 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_smaller(size_t n1, size_t n2);

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	smaller;

	if (*s == '\0' || len == 0 || start >= ft_strlen(s))
	{
		ret = ft_calloc(1, sizeof (char));
		return (ret);
	}
	smaller = ft_smaller(len, ft_strlen(s + start));
	ret = ft_calloc(smaller + 1, sizeof (char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, smaller + 1);
	return (ret);
}

static size_t	ft_smaller(size_t n1, size_t n2)
{
	if ((long double) n1 <= (long double) n2)
		return (n1);
	return (n2);
}
