/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:18:56 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/25 21:44:37 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"
//# include <stdio.h>


typedef struct s_bflags
{
	int	width_parsed;
	int	perc;
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	blank;
	int	plus;
	int	min_width;
	int	precision;
	int	invalid;
}	t_bflags;

int		ft_printf(const char *str, ...);
void	printchar(int *counter, t_bflags bflags, int ch);
void	printstr(int *counter, t_bflags bflags, char *str);
void	printnum(int *counter, t_bflags bflags, int num);
void	printptr(int *counter, t_bflags bflags, size_t ptr);
void	printuns(int *counter, t_bflags bflags, unsigned int num);
void	printbase(char ch, int *ctr, t_bflags bf, unsigned int n, int b);
void	parse_width(const char *str, size_t *i, t_bflags *bflags);
void	parse_precision(const char *str, size_t *i, t_bflags *bflags);
char	digit(unsigned int nbr, int base);
char	change_letter(char ch);
void	ft_free(char **str);
char	*format_number(t_bflags bflags, long num);
char	*format_base(char *str, t_bflags bflags);
char	*width_and_sign(char *str, t_bflags bflags, long num);
char	*width_and_sign_base(char *str, t_bflags bflags, int num, int base);
char	*space(char *str, t_bflags bflags, long num);
char	*space_base(char *str, t_bflags bflags, long num);
char	*width(char *str, t_bflags *bflags, int len, char filler);

#endif
