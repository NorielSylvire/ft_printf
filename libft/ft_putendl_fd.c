/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:56:40 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/14 22:47:55 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(const char *s, int fd)
{
	int	len;

	len = ft_putstr_fd(s, fd);
	len += ft_putchar_fd('\n', fd);
	return (len);
}
