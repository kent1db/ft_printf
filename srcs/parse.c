/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:15:17 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/08 18:02:27 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_get_percent(char *format, int *index)
{
	while (format[*index])
	{
		if (format[*index] == '%')
			return (*index);
		(*index)++;
	}
	return (-1);
}

void	ft_parse_prec(char *format, va_list ap, int *i, t_flags *arg)
{
	dprintf(1, "format = %c\n", format[*i]);
	if (format[*i] == '.')
	{
		dprintf(1, "test\n");
		if (format[++(*i)] == '*')
		{
			arg->prec = va_arg(ap, int);
			if (arg->prec < 0)
				arg->prec = 0;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			arg->prec = ft_atoi(format + (*i));
			while (format[*i] >= '0' && format[*i] <= '9')
				(*i)++;
		}
		else
			arg->prec = 0;
	}
}

void	ft_parse_width(char *format, va_list ap, int *i, t_flags *arg)
{
	if (format[*i] == '*')
	{
		arg->width = va_arg(ap, int);
		if (arg->width < 0)
		{
			arg->minus = 1;
			arg->width = -(arg->width);
		}
		(*i)++;
	}
	else if (format[*i] >= '1' && format[*i] <= '9')
	{
		arg->width = ft_atoi(format + (*i));
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
	else
		arg->width = 0;
}

void	ft_parse_flags(char *format, int *i, t_flags *arg)
{
	if (format[*i] == '0')
	{
		arg->zero = 1;
		(*i)++;
	}
	else
		arg->zero = 0;
	if (format[*i] == '-')
	{
		arg->minus = 1;
		(*i)++;
	}
	else
		arg->minus = 0;
}

void	ft_check_format(char *format, va_list ap, int *ret)
{
	int index;
	t_flags arg;
	
	index = 0;
	if (ft_get_percent(format, &index) != -1)
	{
		index += 1;
		ft_parse_flags(format, &index, &arg);
		ft_parse_width(format, ap, &index, &arg);
		ft_parse_prec(format, ap, &index, &arg);
		dprintf(1, "zero = %d\nminus = %d\nwidth = %d\nprec = %d\n", arg.zero, arg.minus, arg.width, arg.prec);
	}
	else
	{
		*ret = ft_strlen(format);
		ft_putstr_fd(format, 1);
	}
}