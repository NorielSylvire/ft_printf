/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:20:58 by fhongu            #+#    #+#             */
/*   Updated: 2023/07/02 20:33:11 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	parse_width(const char *str, size_t *i, t_bflags *bflags)
{
	bflags->width_parsed = 1;
	while (ft_isdigit(str[*i]))
	{
		bflags->min_width += str[*i] - '0';
		if (ft_isdigit(str[*i + 1]))
			bflags->min_width *= 10;
		*i += 1;
	}
}

void	parse_precision(const char *str, size_t *i, t_bflags *bflags)
{
	bflags->dot = 1;
	*i += 1;
	while (ft_isdigit(str[*i]))
	{
		bflags->precision += str[*i] - '0';
		if (ft_isdigit(str[*i + 1]))
			bflags->precision *= 10;
		*i += 1;
	}
}

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

void	ft_free(char **str)
{
	if (!*str)
		return ;
	free(*str);
	*str = NULL;
}
