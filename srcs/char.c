/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:15:56 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/10 10:22:48 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putc_minus(int *ret, t_flags *arg, char c)
{
	int		count;

	count = 1;
	ft_putchar_fd(c, 1);
	(*ret)++;
	while (count < (arg->width))
	{
		ft_putchar_fd(' ', 1);
		(*ret)++;
		count++;
	}
}

void		ft_putc_none(int *ret, t_flags *arg, char c)
{
	int		count;

	count = 1;
	while (count < (arg->width))
	{
		ft_putchar_fd(' ', 1);
		(*ret)++;
		count++;
	}
	ft_putchar_fd(c, 1);
	(*ret)++;
}

void		ft_print_char(va_list ap, int *ret, t_flags *arg, int *i)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (arg->minus)
		ft_putc_minus(ret, arg, c);
	else
		ft_putc_none(ret, arg, c);
	(*i)++;
}