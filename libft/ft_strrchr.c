/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:23:55 by fhongu            #+#    #+#             */
/*   Updated: 2023/03/17 18:59:22 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	size_t			str;
	unsigned char	ch;

	len = ft_strlen(s);
	if (len > 0 && c % 128 != 0)
		len--;
	str = (unsigned long) s;
	ch = (unsigned char) c;
	if (ch == '\0')
		return ((char *)(str + len));
	while ((str + len) >= str)
	{
		if (*(char *)(str + len) == ch)
			return ((char *)(str + len));
		len--;
	}
	return (NULL);
}
