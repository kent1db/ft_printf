/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:56:41 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/14 18:08:39 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

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
				ft_print_char(ap, ret, arg);
			else if (format[i] == 's')
				ft_print_string(ap, ret, arg);
			else if (format[i] == 'p')
				ft_print_adress(ap, ret, arg);
			else if (format[i] == 'd' || format[i] == 'i')
				ft_print_int(ap, ret, arg);
			else if (format[i] == 'u')
				ft_print_unsigned(ap, ret, arg);
			else if (format[i] == 'x' || format[i] == 'X')
				ft_print_hexa(ap, ret, arg, format[i]);
			else if (format[i] == '%')
				ft_print_percent(ret, arg);
		}
		else
		{
			write(1, &(format[i]), 1);
			(*ret)++;
		}
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

/*int			main(void)
{
	int ret_p;
	int ret_ft;
	char	*str;

	str = "quentin";
	ret_ft = 0;
	ret_p = 0;*/
	
	/*				 TEST CHARACTERE 				*/
	/*dprintf(1, "############printf###########\n");
	dprintf(1, "minus [%-20c%-20c%-20c]\n", 'a', 'b', 'c');
	ret_p =dprintf(1, "none  [%20c][%20c][%20c]\n", 'a', 'b', 'c');
	dprintf(1, "##########ft_printf##########\n");
	ft_printf("minus [%-20c%-20c%-20c]\n", 'a', 'b', 'c');
	ret_ft = ft_printf("none  [%20c][%20c][%20c]\n", 'a', 'b', 'c');*/
	
	/*					TEST STRING					*/
	/*dprintf(1, "############printf###########\n");
	//dprintf(1," %*.0s %.2s ", 10, "123", "4567");
	ret_p = dprintf(1, "29: %4.3s %-4.3s \n", "123", "4567");
	dprintf(1, "33: %4.2s %-4.2s \n", "123", "4567");
	dprintf(1, "##########ft_printf##########\n");
	//ft_printf(" %*.0s %.2s ", 10, "123", "4567");
	ret_ft = ft_printf("29: %4.3s %-4.3s \n", "123", "4567");
	ft_printf("33: %4.2s %-4.2s \n", "123", "4567");*/
	
	/*					TEST ADRESS					*/
	/*dprintf(1, "############printf###########\n");
	//ret_p = dprintf(1, " %p %p ", INT_MIN, INT_MAX);
	dprintf(1, "##########ft_printf##########\n");
	ret_ft = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);*/

	/*					TEST INT					*/
	/*dprintf(1, "############printf###########\n");
	//ret_p = dprintf(1, "%09d\n", UINT_MAX + 1);
	ret_p = dprintf(1, " %s  \n", NULL);
	dprintf(1, "##########ft_printf##########\n");
	//ret_ft = ft_printf("%09d\n", UINT_MAX + 1);
	ret_ft = ft_printf(" %s  \n", NULL);
	
	
	dprintf(1, "#############ret#############\n");
	dprintf(1, "ret_printf    = %d\n", ret_p);
	dprintf(1, "ret_ft_printf = %d\n", ret_ft);
	
	return (0);
}*/