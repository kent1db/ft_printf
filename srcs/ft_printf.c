/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:56:41 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/07 17:57:59 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);


	va_end(ap);
}*/

#include <stdio.h>

int		main(void)
{
	int n1;
	//int n2;
	printf("#######################\n");
	n1 = printf("printf : %s\n", "ceci est un test");
	printf("ret = %d\n", n1);
	ft_putnbr_fd(42, 1);
	return (0);
}