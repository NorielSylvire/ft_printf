/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:42:52 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/27 22:17:02 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	print_width(char **str, t_flags flags, char *arg);

void	printstr_bonus(char **str, t_flags flags, char *arg)
{
	int	will_print;

	if (flags.dot && flags.precision == 0)
		arg = NULL;
	will_print = (int) ft_strlen(arg);
	if (flags.precision != 0 && will_print != 0
		&& flags.precision < will_print)
		will_print = flags.precision;
	flags.min_width -= will_print;
	print_width(str, flags, arg);
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
static void	print_width(char **str, t_flags flags, char *arg)
{
	size_t	idx;

	if (flags.dot)
	{
		idx = flags.precision - 1;
	}
	else
	{
		idx = -2;
	}
	if (flags.minus)
	{
		*str = ft_append(*str, ft_substr(arg, 0, idx + 1), 1, 1);
		while (flags.min_width-- > 0)
			*str = ft_append(*str, " ", 1, 0);
	}
	else
	{
		while (flags.min_width-- > 0)
			*str = ft_append(*str, " ", 1, 0);
		*str = ft_append(*str, ft_substr(arg, 0, idx + 1), 1, 1);
	}
}
