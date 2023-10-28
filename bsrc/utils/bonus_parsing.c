/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:51:08 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/27 22:35:11 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include <sys/wait.h>

static void	parse_width(const char *str, size_t *i, t_flags *flags);
static void	parse_precision(const char *str, size_t *i, t_flags *flags);

void	parse_bonus(const char *str, size_t *i, t_flags *flags)
{
	while (ft_strchr("-.# +", str[*i]) || ft_isdigit(str[*i]))
	{
		if (str[*i] == '-' && !flags->width_parsed)
			flags->minus = 1;
		else if (str[*i] == '0' && !flags->zero && !flags->width_parsed)
			flags->zero = 1;
		else if (ft_isdigit(str[*i]) && !flags->width_parsed && str[*i != '0'])
			parse_width(str, i, flags);
		else if (str[*i] == '.' && !flags->dot)
			parse_precision(str, i, flags);
		else if (str[*i] == '#' && !flags->hash && !flags->width_parsed)
			flags->hash = 1;
		else if (str[*i] == ' ' && !flags->blank && !flags->width_parsed)
			flags->blank = 1;
		else if (str[*i] == '+' && !flags->plus && !flags->width_parsed)
			flags->plus = 1;
		else
		{
			flags->invalid = 1;
			break ;
		}
		if (!flags->width_parsed && !flags->dot)
			*i += 1;
	}
}

static void	parse_width(const char *str, size_t *i, t_flags *flags)
{
	flags->width_parsed = 1;
	while (ft_isdigit(str[*i]))
	{
		flags->min_width += str[*i] - '0';
		if (ft_isdigit(str[*i + 1]))
			flags->min_width *= 10;
		*i += 1;
	}
}

static void	parse_precision(const char *str, size_t *i, t_flags *flags)
{
	flags->dot = 1;
	*i += 1;
	while (ft_isdigit(str[*i]))
	{
		flags->precision += str[*i] - '0';
		if (ft_isdigit(str[*i + 1]))
			flags->precision *= 10;
		*i += 1;
	}
}
