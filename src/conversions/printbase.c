/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:00:14 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/11 21:40:50 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static char	change_letter(char ch);

void	printbase(char ch, int *ctr, t_bflags bf, unsigned int n, int b)
{
	char			*str;
	char			*filler;
	char			*bases = BASES;
	unsigned  int	nbr;
	unsigned  short	ndigits;

	filler = ft_calloc(2, sizeof (char));
	*filler = ' ';
	if (bf.zero && !bf.minus)
		*filler = '0';
	nbr = n;
	ndigits = 1;
	while (nbr > (unsigned int) b)
	{
		nbr /= (unsigned int) b;
		ndigits += 1;
	}
	str = ft_calloc(ndigits + 1, sizeof (char));
	while (ndigits > 0)
	{
		str[--ndigits] = bases[n % b];
		if (ch == 'X')
			str[ndigits] = change_letter(str[ndigits]);
		n /= b;
	}
	if (bf.plus || bf.blank)
		bf.min_width--;
	while (bf.min_width--)
	{
		if (bf.minus)
			str = ft_append(str, filler);
		else
			str = ft_preppend(str, filler);
	}
	if (bf.plus)
		str = ft_preppend(str, "+");
	else if (bf.blank)
		str = ft_preppend(str, " ");
	*ctr += ft_putstr_fd(str, 1);
}

static char	change_letter(char ch)
{
	if (ft_isupper((int) ch))
		ch -= 'a' - 'A';
	else
		ch += 'a' - 'A';
	return (ch);
}
