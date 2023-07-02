/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:00:14 by fhongu            #+#    #+#             */
/*   Updated: 2023/07/02 19:47:06 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static char	*make_string(t_bflags bf, unsigned int n, int b);
static char	*capitalize(char *str);

void	printbase(int *ctr, t_bflags bf, unsigned int n, int b)
{
	char	*str;

	str = make_string(bf, n, b);
	str = width_and_sign_base(str, bf, n, b);
	*ctr += ft_putstr_fd(str, 1);
	ft_free(&str);
}

static char	*make_string(t_bflags bf, unsigned int n, int b)
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
	if (bf.uppercase == 1)
		str = capitalize(str);
	str = format_base(str, bf);
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
