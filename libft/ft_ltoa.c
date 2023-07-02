/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:53:51 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/24 18:55:49 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse_integer(char *str, long n);

char	*ft_ltoa(long n)
{
	long	nbr;
	short	ndigits;
	char	*ret;

	nbr = n;
	ndigits = 0;
	while (n > 9 || n < -9)
	{
		ndigits++;
		n /= 10;
	}
	if (nbr < 0)
		ndigits += 3;
	else
		ndigits += 2;
	ret = ft_calloc(ndigits, sizeof (char));
	if (!ret)
		return (NULL);
	if (nbr < 0)
	{
		*ret = '-';
		nbr *= -1;
	}
	recurse_integer(ret + ndigits - 2, nbr);
	return (ret);
}

static void	recurse_integer(char *str, long n)
{
	if (n > 9)
	{
		recurse_integer(str - 1, n / 10);
		*str = '0' + n % 10;
	}
	else
		*str = '0' + n;
}
