/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:04:04 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/10 16:49:44 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*static void		ft_puts_minus(int *ret, char *str, t_flags *arg)
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
}*/

static void		ft_puts_none(int *ret, char *str, t_flags *arg, int len)
{
	int		count;
	int 	i;

	i = 0;
	if ((arg->prec) != -1 && (arg->prec) < len)
		count = (arg->width) - (arg->prec);
	else
		count = (arg->width) - len;
	while (count != 0)
	{
		ft_putchar_fd(' ', 1);
		count--;
		(*ret)++;
	}
	if (arg->prec != -1)
	{
		while((i < (arg->prec)) && str[i])
		{
			ft_putchar_fd(str[i++], 1);
			(*ret)++;
		}
	}
	else
		ft_putstr_fd(str, 1);		
}

void	ft_print_string(va_list ap, int *ret, t_flags *arg)
{
	char	*str;
	int		len;
	
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	/*if (arg->minus || arg->width <= len)
		ft_puts_minus(ret, str, arg);*/
	/*else*/
		ft_puts_none(ret, str, arg, len);
}