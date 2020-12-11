/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:34:41 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/11 18:18:38 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*static	void	ft_put_int_minus(int *ret, int nb, t_flags *arg, int len)
{
	
}

static void		ft_put_int_zero(int *ret, int nb, t_flags *arg, int len)
{
	
}*/

static void		ft_put_int_none(int *ret, int nb, t_flags *arg, int len, int signe)
{
	int 		count_s;
	int			count_z;
	
	if (arg->prec > len)
		count_z = arg->prec - len;
 	if (arg->prec <= len)
		count_z = 0;
	if (arg->prec >= arg->width)
		count_s = 0;
	if (arg->prec < arg->width)
	{
		if (count_z == 0)
			count_s = arg->width - len - signe;
		else
			count_s = arg->width - arg->prec - signe;
	}
	while (count_s--)
		(*ret) += ft_putc(' ', 1);
	if (signe)
		(*ret) += ft_putc('-', 1);
	while (count_z--)
		(*ret) += ft_putc('0', 1);
	(*ret) += ft_putnb_pos(nb);
}

void		ft_print_int(va_list ap, int *ret, t_flags *arg)
{
	int		nb;
	int		len;
	int		signe;
	
	signe = 0;
	nb = va_arg(ap, int);
	if (arg->prec == -1)
		arg->prec = 0;
	if (nb < 0)
	{
		signe = 1;
		nb = -nb;
	}
	len = ft_count_int(nb);
	/*if (arg->minus)
		ft_put_int_minus(ret, nb, arg, len);
	else if (arg->zero)
		ft_put_int_zero(ret, nb, arg, len);
	else*/
		ft_put_int_none(ret, nb, arg, len, signe);
}