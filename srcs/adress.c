/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:02:39 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/11 17:45:36 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int			ft_put_hexa(long long nb)
{
	long long	base_l;
	char		*base;

	base = "0123456789abcdef";
	base_l = 16;
	if (nb >= base_l)
		return (ft_put_hexa(nb / base_l) + ft_putc(base[nb % base_l], 1));
	return (ft_putc(base[nb % base_l], 1));
}

static int			ft_count_hexa(long long nb)
{
	long long	base_l;
	char		*base;

	base = "0123456789abcdef";
	base_l = 16;
	if (nb >= base_l)
		return (ft_count_hexa(nb / base_l) + 1);
	return (1);
}

static void			ft_putadd_minus(int *ret, t_flags *arg, long long adress)
{
	int			count;

	count = ft_puts("0x") + ft_put_hexa(adress);
	while (count < arg->width)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	(*ret) += count;
}

static void			ft_putaddd_none(int *ret, t_flags *arg, long long adress)
{
	int			count;

	count = ft_count_hexa(adress) + 2;
	while (arg->width > count)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	ft_puts("0x");
	ft_put_hexa(adress);
	(*ret) += count;
}

void			ft_print_adress(va_list ap, int *ret, t_flags *arg)
{
	long long	adress;

	(void)arg;
	adress = (long long)va_arg(ap, char *);
	if (arg->minus)
		ft_putadd_minus(ret, arg, adress);
	else
		ft_putaddd_none(ret, arg, adress);
}
