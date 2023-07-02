/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:32:07 by fhongu            #+#    #+#             */
/*   Updated: 2023/07/02 20:11:44 by fhongu           ###   ########.fr       */
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
		ft_free(&str);
		str = "(null)";
	}
	will_print = (int) ft_strlen(str);
	if (bflags.precision != 0 && will_print != 0
		&& bflags.precision < will_print)
		will_print = bflags.precision;
	bflags.min_width -= will_print;
	print_width(counter, bflags, str);
}

static void	print_width(int *counter, t_bflags bflags, char *str)
{
	if (bflags.minus)
	{
		*counter += ft_putsubstr_fd(str, 0, bflags.precision - 1, 1);
		while (bflags.min_width-- > 0)
			*counter += ft_putchar_fd(' ', 1);
	}
	else
	{
		while (bflags.min_width-- > 0)
			*counter += ft_putchar_fd(' ', 1);
		*counter += ft_putsubstr_fd(str, 0, bflags.precision - 1, 1);
	}
}
