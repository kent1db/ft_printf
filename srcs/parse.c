/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:15:17 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/08 15:29:15 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_format(char *format, va_list ap, int *ret, int i)
{
	t_flags *arg;
	
	ft_parse_flags(format, ap, &i, arg);
	ft_parse_width(format, ap, &i, arg);
	ft_parse_prec(format, ap, &i, arg);
}

void	ft_parse_flags(char *format, va_list ap, int *i, t_flags *arg)
{
	while (format[*i])
	{
		if (format[*i] == '0')
			arg->zero = 1;
		else
			arg->zero = 0;
		
		if (format[*i] == '-')
			arg->minus = 1;
	}
}

/*
		if (format[i] == '*')
		{
			arg->width = va_arg(ap, int);
			if (arg->width < 0)
			{
				arg->minus = 1;
				arg->width = -arg->width;
			}
		}
		while (format[i] >= '1' && format[i] <= '9')
			arg->width = arg->width * 10 + format[i++] - '0';
		if (format[i] == '.')
		{
			if (format[++i] == '*')
				arg->prec = va_arg(ap, int);
			while (format[i] >= '1' && format[i] <= '9')
				arg->prec = arg->prec * 10 + format[i++] - '0';
			if (arg->prec < 0)
			{
				arg->prec = 0;
				i++;
			}				
		}
		else
			i++;
	}
}*/

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

void	ft_check_format(char *format, va_list ap, int *ret)
{
	int index;
	
	index = 0;
	if (ft_get_percent(format, &index) != -1)
		ft_parse_format(format, ap, ret, index);
	else
	{
		*ret = ft_strlen(format);
		ft_putstr_fd(format, 1);
	}
}