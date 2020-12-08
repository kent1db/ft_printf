/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:15:17 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/08 14:20:42 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_parse_format(char *format, va_list ap, int *ret, int i)
{
	t_flags *arg;

	while (format[i])
	{
		if (format[i] == '0')
			arg->zero = 1;
		if (format[i] == '-')
			arg->minus = 1;
		if (format[i] == '*')
			ft_parse_format(ft_itoa(va_arg(ap, int)), ap, ret, i);
		while (format[i] >= '1' && format[i] <= '9')
			arg->width = arg->width * 10 + format[i++] - '0';
		i++;
	}
}

int		ft_get_percent(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '%')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_check_format(char *format, va_list ap, int *ret)
{
	int index;
	
	index = 0;
	if (ft_get_percent(format, index) != -1)
		ft_parse_format(format, ap, ret, index);
	else
	{
		*ret = ft_strlen(format);
		ft_putstr_fd(format, 1);
	}
}