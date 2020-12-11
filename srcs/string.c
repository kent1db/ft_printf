/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:04:04 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/11 15:38:41 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		ft_puts_minus(int *ret, char *str, t_flags *arg, int len)
{
	int		i;

	i = 0;
	if (arg->prec == 0)
	{
		(*ret) += ft_puts(str);
		i = len;
	}
	else
	{
		while ((i < (arg->prec)) && str[i])
		{
			ft_putchar_fd(str[i++], 1);
			(*ret)++;
		}
	}
	if (arg->width > len)
	{
		while (i < (arg->width))
		{
			ft_putchar_fd(' ', 1);
			(*ret)++;
			i++;
		}
	}
}

static void		ft_puts_none(int *ret, char *str, t_flags *arg, int len)
{
	int		count;
	int 	i;

	i = 0;
	if (arg->prec >= len || arg->prec == 0)
		count = arg->width - len;
	else
		count = arg->width - arg->prec;
	while (count > 0)
	{
		ft_putchar_fd(' ', 1);
		count--;
		(*ret)++;
	}
	if (arg->prec == 0)
	{
		(*ret) += ft_puts(str);
		i = len;
	}
	while((i < (arg->prec)) && str[i])
	{
		ft_putchar_fd(str[i++], 1);
		(*ret)++;
	}
}

void			ft_print_string(va_list ap, int *ret, t_flags *arg)
{
	char		*str;
	int			len;
	
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if (arg->prec == -1)
		(*ret) += ft_putc(' ', arg->width);
	else if (arg->minus)
		ft_puts_minus(ret, str, arg, len);
	else
		ft_puts_none(ret, str, arg, len);
}