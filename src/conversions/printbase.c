/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:00:14 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/27 22:14:41 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static char	*make_string(t_flags fl, unsigned int n, int b);
static char	*capitalize(char *str);

void	printbase(char **str, t_flags fl, unsigned int n, int b)
{
	char	*res;

	res = make_string(fl, n, b);
	if (BONUS)
		res = width_and_sign_base(res, fl, n, b);
	*str = ft_append(*str, res, 1, 1);
}

static char	*make_string(t_flags fl, unsigned int n, int b)
{
	char			*str;
	unsigned int	nbr;
	unsigned short	ndigits;

	nbr = n;
	ndigits = 1;
	while (nbr >= (unsigned int) b)
	{
		nbr /= (unsigned int) b;
		ndigits += 1;
	}
	str = ft_calloc(ndigits + 1, sizeof (char));
	while (ndigits > 0)
	{
		str[--ndigits] = digit(n, b);
		n /= b;
	}
	if (fl.uppercase == 1)
		str = capitalize(str);
	if (BONUS)
		str = format_base(str, fl);
	return (str);
}

static char	*capitalize(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = change_letter(str[i]);
		i++;
	}
	return (str);
}
