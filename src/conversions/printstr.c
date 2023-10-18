/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:32:07 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/15 21:55:42 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	print_width(int *counter, t_bflags bflags, char *str);

void	printstr(int *counter, t_bflags bflags, char *str)
{
	int	will_print;

	if (bflags.dot && bflags.precision == 0)
		str = NULL;
	else if (!str)
	{
		ft_free((void **) &str);
		str = "(null)";
	}
	will_print = (int) ft_strlen(str);
	if (bflags.precision != 0 && will_print != 0
		&& bflags.precision < will_print)
		will_print = bflags.precision;
	bflags.min_width -= will_print;
	print_width(counter, bflags, str);
}

/** @brief 
*
* This function prints a string along with its width chars.
* It will only print as many chars from the string as its precision.
* The precision gets subtracted by one so that when it is 0, aka, not set,
* it will overflow to the max value and therefore print the entire string.
* If this wasn't done, when the user didn't specify a precision, it would
* be parsed as 0 and no chars would be printed.
*
*/
static void	print_width(int *counter, t_bflags bflags, char *str)
{
	size_t	idx;

	if (bflags.dot)
	{
		idx = bflags.precision - 1;
	}
	else
	{
		idx = -2;
	}
	if (bflags.minus)
	{
		*counter += ft_putsubstr_fd(str, 0, idx, 1);
		while (bflags.min_width-- > 0)
			*counter += ft_putchar_fd(' ', 1);
	}
	else
	{
		while (bflags.min_width-- > 0)
			*counter += ft_putchar_fd(' ', 1);
		*counter += ft_putsubstr_fd(str, 0, idx, 1);
	}
}
