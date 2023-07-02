/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsubstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:37:44 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/24 20:52:55 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putsubstr_fd(const char *str, size_t start, size_t end, int fd)
{
	int		result;
	size_t	i;

	result = 0;
	i = start;
	while (i <= end && str && str[i])
		result += ft_putchar_fd(str[i++], fd);
	return (result);
}
