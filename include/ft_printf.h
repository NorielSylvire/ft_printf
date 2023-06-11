/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:18:56 by fhongu            #+#    #+#             */
/*   Updated: 2023/06/11 19:55:09 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASES "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>


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
void	parse_nbr(const char *str, size_t *i, t_bflags *bflags);

#endif
