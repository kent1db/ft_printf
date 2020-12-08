/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:56:53 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/08 17:04:22 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../Libft/includes/libft.h"
# include "struct.h"

void	ft_check_format(char *format, va_list ap, int *ret);
void	ft_parse_flags(char *format, int *i, t_flags *arg);
void	ft_parse_width(char *format, va_list ap, int *i, t_flags *arg);
void	ft_parse_prec(char *format, va_list ap, int *i, t_flags *arg);

#endif
