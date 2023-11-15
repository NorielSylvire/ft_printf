/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:01:16 by fhongu            #+#    #+#             */
/*   Updated: 2023/11/15 09:14:06 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdlib.h>

typedef struct s_flags
{
	int	width_parsed;
	int	perc;
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	blank;
	int	plus;
	int	uppercase;
	int	min_width;
	int	precision;
	int	invalid;
	int	nullChars;
}	t_flags;

void	printchar_bonus(char **str, t_flags flags, char *apd);
void	printstr_bonus(char **str, t_flags flags, char *arg);
void	format_number(t_flags flags, char **str);
char	*width_and_sign(char *str, t_flags flags, int negative);
char	*space(char *str, t_flags flags, long num);
char	*width(char *str, t_flags *flags, int len, char filler);
char	*format_base(char *str, t_flags flags);
char	*width_and_sign_base(char *str, t_flags flags, int num, int base);
char	*space_base(char *str, t_flags flags, long num);
void	parse_bonus(const char *str, size_t *i, t_flags *flags);

#endif
