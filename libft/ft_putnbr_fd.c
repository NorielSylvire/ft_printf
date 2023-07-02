/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:01:26 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/04 21:21:10 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recurse_nbr(long n, int fd);

int	ft_putnbr_fd(int n, int fd)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = (long) n;
	if (nbr < 0)
	{
		len += ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	len += recurse_nbr(nbr, fd);
	return (len);
}

static int	recurse_nbr(long n, int fd)
{
	int		len;
	char	c;

	if (n > 9)
	{
		recurse_nbr(n / 10, fd);
		c = n % 10 + '0';
		len = ft_putchar_fd(c, fd);
	}
	else
	{
		c = n + '0';
		len = ft_putchar_fd(c, fd);
	}
	return (len);
}
