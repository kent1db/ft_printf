/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:56:41 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/08 18:09:49 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_printf(const char *format, ...)
{
	int		ret;
	va_list ap;

	ret = 0;
	va_start(ap, format);
	ft_check_format((char *)format, ap, &ret);
	va_end(ap);
	return (ret);
}

int			main(void)
{
	dprintf(1, "############printf###########\n");
	dprintf(1, "[%10.*d]\n", -10, 42);
	dprintf(1, "############parse############\n");
	ft_printf("Bonjour %10.*d\n", -10);
	return (0);
}
