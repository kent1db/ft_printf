/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:56:41 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/10 10:26:25 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*static void		print_struct(t_flags *arg)
{
	dprintf(1, "\n############struct###########\n");
	dprintf(1, "zero = %d\n", arg->zero);
	dprintf(1, "minus = %d\n", arg->minus);
	dprintf(1, "width = %d\n", arg->width);
	dprintf(1, "prec = %d\n", arg->prec);
	dprintf(1, "start = %d\n", arg->start);
	dprintf(1, "end = %d\n", arg->end);
	dprintf(1, "#############################\n");
}*/

void		ft_print(char *format, va_list ap, int *ret, t_flags *arg)
{
	int i;
	
	i = -1; 
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ft_parse_format(format, ap, arg, &i);
			if (format[i] == 'c')
				ft_print_char(ap, ret, arg, &i);
			/*else if (format[i] == 's')
				ft_print_string(ap, ret, arg);
			else if (format[i] == 'p')
				ft_print_adress(ap, ret, arg);
			else if (format[i] == 'd' || format[i] == 'i')
				ft_print_int(ap, ret, arg);
			else if (format[i] == 'u')
				ft_print_unsigned(ap, ret, arg);
			else if (format[i] == 'x' || format[i] == 'X')
				ft_print_hexa(ap, ret, arg);
			else if (format[i] == '%')
				ft_print_percent(ap, ret, arg);*/
			i++;
		}
		write(1, &(format[i]), 1);
		(*ret)++;
	}
}

int			ft_printf(const char *format, ...)
{
	int		ret;
	va_list ap;
	t_flags	arg;
	
	ret = 0;
	va_start(ap, format);
	arg.len = ft_strlen(format);
	if (ft_get_percent((char *)format) == -1)
	{
		ft_putstr_fd((char *)format, 1);
		return (arg.len);
	}
	ft_print((char *)format, ap, &ret, &arg);
	va_end(ap);
	return (ret);
}

int			main(void)
{
	dprintf(1, "############printf###########\n");
	//dprintf(1, "Hello bonjour%.5dbonjour%*.2dtest tab = \t\n", 42, 10, 202);
	dprintf(1, "minus [%-20c]\n", 'a');
	dprintf(1, "none  [%20c]\n", 'a');
	dprintf(1, "##########ft_printf##########\n");
	//ft_printf("Hello bonjour%.5dbonjour%*.2dtest tab = \t\n", 42, 10, 202);
	ft_printf("minus [%-20c]\n", 'a');
	ft_printf("none  [%20c]\n", 'a');
	return (0);
}
