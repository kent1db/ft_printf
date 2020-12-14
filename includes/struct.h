/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:27:25 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/14 17:06:48 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_flags
{
	int			zero;
	int			minus;
	int			width;
	int			prec;
	int			start;
	int			end;
	int			len;
	int			hexa;
}				t_flags;

#endif
