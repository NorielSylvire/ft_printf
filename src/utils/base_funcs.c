/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:20:58 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/23 20:36:17 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	digit(unsigned int nbr, int base)
{
	char			*digits;
	unsigned int	remainder;

	digits = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	remainder = nbr % base;
	if (remainder <= 9)
		return (remainder + '0');
	else
		return (digits[remainder - 10]);
}

char	change_letter(char ch)
{
	if (ft_isdigit((int) ch))
		return (ch);
	if (ft_isupper((int) ch))
		ch += 'a' - 'A';
	else
		ch -= 'a' - 'A';
	return (ch);
}
