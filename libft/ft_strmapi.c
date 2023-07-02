/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:17:01 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/14 22:46:42 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;
	unsigned int	slen;

	slen = ft_strlen(s);
	ret = ft_calloc(slen + 1, sizeof (char));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		*ret++ = (*f)(i++, *s);
		s++;
	}
	ret -= slen;
	return (ret);
}
