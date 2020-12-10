/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:15:17 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/10 16:35:30 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		ft_parse_prec(char *format, va_list ap, int *i, t_flags *arg)
{
	if (format[*i] == '.')
	{
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
	else
		arg->prec = -1;
}

void		ft_parse_width(char *format, va_list ap, int *i, t_flags *arg)
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

void		ft_parse_flags(char *format, int *i, t_flags *arg)
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

void		ft_parse_format(char *format, va_list ap, t_flags *arg, int *index)
{
	arg->start = (*index);
	(*index)++;
	ft_parse_flags(format, index, arg);
	ft_parse_width(format, ap, index, arg);
	ft_parse_prec(format, ap, index, arg);
	arg->end = (*index);
}
