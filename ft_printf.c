/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:31:42 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/03 21:07:50 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_bflags(t_bflags *bflags);
static void	parse_bonus(const char *str, size_t *i, t_bflags *blfags);
static void	parse_conversion(const char *str, size_t i, t_bflags bflags);

int	ft_printf(const char *str, ...)
{
	static int	count;
	size_t		i;
	t_bflags	bonus_flags;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			init_bflags(&bonus_flags);
			if (ft_strchr("-.# +", str[i + 1]) || ft_isdigit(str[i + 1]))
			{
				parse_bonus(str, &i, &bonus_flags);
			}
			else if (ft_strchr("cspdiuxX%", str[i]) && !bonus_flags.invalid)
			{
				parse_conversion(str, i, bonus_flags);
			}
		}
		i++;
	}
	return (count);
}

static void	init_bflags(t_bflags *bflags)
{
	bflags->width_parsed = 0;
	bflags->perc = 0;
	bflags->minus = 0;
	bflags->zero = 0;
	bflags->dot = 0;
	bflags->hash = 0;
	bflags->blank = 0;
	bflags->plus = 0;
	bflags->min_width = 0;
	bflags->invalid = 0;
}

static void	parse_bonus(const char *str, size_t *i, t_bflags *bflags)
{
	*i += 1;
	while (ft_strchr("-.# +", str[*i]) || ft_isdigit(str[*i]))
	{
		if (str[*i] == '-' && !bflags->minus)
			bflags->minus = 1;
		else if (str[*i] == '.' && !bflags->dot)
			bflags->dot = 1;
		else if (str[*i] == '#' && !bflags->hash)
			bflags->hash = 1;
		else
			bflags->invalid = 1;
		*i += 1;
	}
}
