/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:18:56 by fhongu            #+#    #+#             */
/*   Updated: 2023/10/27 19:58:01 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef BONUS
#  define BONUS 0
# endif
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "./ft_printf_bonus.h"

int		ft_printf(const char *str, ...);
void	printchar(char **str, t_flags flags, int ch);
void	printstr(char **str, t_flags flags, char *arg);
void	printnum(char **str, t_flags flags, int num);
void	printptr(char **str, t_flags flags, size_t ptr);
void	printuns(char **str, t_flags flags, unsigned int num);
void	printbase(char **str, t_flags fl, unsigned int n, int b);
char	digit(unsigned int nbr, int base);
char	change_letter(char ch);

#endif
