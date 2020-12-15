/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:11:52 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/15 10:13:59 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putp_minus(int *ret, t_flags *arg)
{
	int		count;

	count = 1;
	(*ret) += ft_putc('%', 1);
	while (count < (arg->width))
	{
		ft_putchar_fd(' ', 1);
		count++;
		(*ret)++;
	}
	(*ret) = count;
}

void		ft_putp_none(int *ret, t_flags *arg)
{
	int		count;

	count = 1;
	while (count < (arg->width))
	{
		ft_putchar_fd(' ', 1);
		count++;
		(*ret)++;
	}
	(*ret) += ft_putc('%', 1);
}

void		ft_putp_zero(int *ret, t_flags *arg)
{
	int		count;

	count = 1;
	while (count < (arg->width))
	{
		ft_putchar_fd('0', 1);
		count++;
		(*ret)++;
	}
	(*ret) += ft_putc('%', 1);
}

void		ft_print_percent(int *ret, t_flags *arg)
{
	if (arg->minus)
		ft_putp_minus(ret, arg);
	else if (arg->zero)
		ft_putp_zero(ret, arg);
	else
		ft_putp_none(ret, arg);
}
