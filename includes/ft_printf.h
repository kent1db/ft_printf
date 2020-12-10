/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:56:53 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/10 14:18:53 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../Libft/includes/libft.h"
# include "struct.h"

int		ft_printf(const char *format, ...)
		__attribute__ ((format (printf, 1, 2)));

void	ft_parse_format(char *format, va_list ap, t_flags *arg, int *index);
void	ft_parse_flags(char *format, int *i, t_flags *arg);
void	ft_parse_width(char *format, va_list ap, int *i, t_flags *arg);
void	ft_parse_prec(char *format, va_list ap, int *i, t_flags *arg);

void	ft_print(char *format, va_list ap, int *ret, t_flags *arg);

void	ft_print_string(va_list ap, int *ret, t_flags *arg);
void	ft_print_adress(va_list ap, int *ret, t_flags *arg);
void	ft_print_int(va_list ap, int *ret, t_flags *arg);
void	ft_print_unsigned(va_list ap, int *ret, t_flags *arg);
void	ft_print_hexa(va_list ap, int *ret, t_flags *arg);
void	ft_print_percent(va_list ap, int *ret, t_flags *arg);

void	ft_print_char(va_list ap, int *ret, t_flags *arg);
void	ft_putc_none(int *ret, t_flags *arg, char c);
void	ft_putc_minus(int *ret, t_flags *arg, char c);

void	ft_print_string(va_list ap, int *ret, t_flags *arg);

int		ft_get_percent(char *format);

#endif
