/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:56:41 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/08 13:29:22 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int ret;

	ret = 0;
	va_list ap;
	va_start(ap, format);
	ft_check_format((char *)format, ap, &ret);
	va_end(ap);
	return (ret);
}

#include <stdio.h>

int		main(void)
{
	int n1;
	int n2;
	dprintf(1, "#######################\nprintf :");
	n1 = printf("\nBonjour %25% je suis quentin\n");
	printf("ret = %d\n", n1);
	dprintf(1, "#######################\nft_printf :");
	n2 = ft_printf("\nBonjour %%%%d je suis quentin\n");
	printf("ret = %d\n", n2);
	return (0);
}