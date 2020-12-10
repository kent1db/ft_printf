/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:04:04 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/10 14:15:32 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_puts_minus(int *ret, char *str, t_flags *arg)
{
	int		i;

	i = 0;
	while ((i < (arg->prec)) && str[i])
	{
		ft_putchar_fd(str[i++], 1);
		(*ret)++;
	}
	while (i < (arg->width))
	{
		ft_putchar_fd(' ', 1);
		(*ret)++;
	}
}

void		ft_puts_none(int *ret, char *str, t_flags *arg, int len)
{
	int		count;
	int 	i;

	if ((arg->prec) < len)
		count = (arg->width) - (arg->prec);
	else
		count = (arg->width) - len;
	while (count != 0)
	{
		ft_putchar_fd(' ', 1);
		count--;
		(*ret)++;
	}
	while((i < (arg->prec)) && str[i])
	{
		ft_putchar_fd(str[i++], 1);
		(*ret)++;
	}
}

void	ft_print_string(va_list ap, int *ret, t_flags *arg)
{
	char	*str;
	int		len;
	
	len = ft_strlen(str);
	str = va_arg(ap, char *);
	if (arg->minus || arg->width <= len)
		ft_puts_minus(ret, str, arg);
	else
		ft_puts_none(ret, str, arg, len);
}