/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:17:54 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/24 20:18:15 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr_fd(const char *s, int fd)
{
	int	len;

	len = 0;
	while (*s)
	{
		len += ft_putchar_fd(*s, fd);
		s++;
	}
	return (len);
}
