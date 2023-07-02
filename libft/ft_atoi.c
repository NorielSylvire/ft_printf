/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:11:43 by fhongu            #+#    #+#             */
/*   Updated: 2023/04/09 22:58:21 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c);

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 0;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res += *str - '0';
		if (ft_isdigit(*(str + 1)))
			res *= 10;
		str++;
	}
	if (sign)
		res *= -1;
	return ((int) res);
}

static int	ft_isspace(const char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
