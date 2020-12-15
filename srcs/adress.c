/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:02:39 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/15 12:54:53 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int				ft_put_hexa_ll(unsigned long long nb)
{
	unsigned long long	base_l;
	char				*base;

	base = "0123456789abcdef";
	base_l = 16;
	if (nb >= base_l)
		return (ft_put_hexa_ll(nb / base_l) + ft_putc(base[nb % base_l], 1));
	return (ft_putc(base[nb % base_l], 1));
}

static int				ft_count_hexa_ll(unsigned long long nb)
{
	unsigned long long	base_l;
	char				*base;

	base = "0123456789abcdef";
	base_l = 16;
	if (nb >= base_l)
		return (ft_count_hexa_ll(nb / base_l) + 1);
	return (1);
}

static void				ft_putadd_minus(int *ret, t_flags *arg,
						unsigned long long adress)
{
	int					count;

	count = ft_puts("0x") + ft_put_hexa_ll(adress);
	while (count < arg->width)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	(*ret) += count;
}

static void				ft_putadd_none(int *ret, t_flags *arg,
						unsigned long long adress)
{
	int					count;

	count = ft_count_hexa_ll(adress) + 2;
	while (arg->width > count)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	ft_puts("0x");
	ft_put_hexa_ll(adress);
	(*ret) += count;
}

void					ft_print_adress(va_list ap, int *ret, t_flags *arg)
{
	unsigned long long	adress;

	adress = (unsigned long long)va_arg(ap, char *);
	if (adress == 0 && arg->prec == -1)
		(*ret) += ft_puts("0x");
	else if (arg->minus)
		ft_putadd_minus(ret, arg, adress);
	else
		ft_putadd_none(ret, arg, adress);
}
