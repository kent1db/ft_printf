/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:15:17 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/08 16:29:47 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_get_percent(char *format, int *index)
{
	while (format[*index])
	{
		if (format[*index] == '%')
			return (index);
		(*index)++;
	}
	return (-1);
}

void	ft_parse_prec(char *format, va_list ap, int *i, t_flags *arg)
{
	if (format[*i] == '.')
	{
		if (format[++(*i)] == '*')
			arg->prec = va_arg(ap, int);
		else if (format[*i] == '-')
		{
			(*i)++;
			while (is_digit(format[(*i)]))
				(*i)++;
			arg->prec = 0;
		}
		else if (format[*i] >= '1' && format[*i] <= '9')
		{
			while (format[*i] >= '1' && format[*i] <= '9')
				arg->prec = arg->prec * 10 + format[(*i)++] - '0';
		}
		else if(!arg->prec)
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
		while (format[*i] >= '1' && format[*i] <= '9')
			arg->width = arg->width * 10 + format[(*i)++] - '0';
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
	t_flags *arg;
	
	index = 0;
	if (ft_get_percent(format, &index) != -1)
	{
		index += 1;
		ft_parse_flags(format, &index, arg);
		ft_parse_width(format, ap, &index, arg);
		ft_parse_prec(format, ap, &index, arg);
	}
	else
	{
		*ret = ft_strlen(format);
		ft_putstr_fd(format, 1);
	}
}