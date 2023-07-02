/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:56:36 by fhongu            #+#    #+#             */
/*   Updated: 2023/04/09 22:50:33 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_result(const char *source, size_t n);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char const	*scopy;

	scopy = s1;
	len = ft_strlen(s1);
	if (!*set && !len)
	{
		len++;
		return (return_result(s1, len));
	}
	while (ft_strchr(set, *(scopy + len)) && len > 0)
		len--;
	if (len > 0)
	{
		while (*scopy && ft_strchr(set, *scopy))
			scopy++;
		len -= (size_t) scopy - (size_t) s1 - 1;
	}
	return (return_result(scopy, len + 1));
}

static char	*return_result(const char *source, size_t n)
{
	char	*ret;

	ret = malloc(n);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, source, n);
	return (ret);
}
