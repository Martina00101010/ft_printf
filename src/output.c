/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:20:04 by pberge            #+#    #+#             */
/*   Updated: 2019/10/01 03:40:08 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

/*
** refresh buffer if there is no space left
*/

void	add_to_output(t_vaio *v, char *to_print)
{
	ft_putnbr(BUFFLEN - v->len - (int)ft_strlen(to_print));
	if (BUFFLEN - v->len - (int)ft_strlen(to_print) < 0)
	{
		write(1, v->to_print, v->len);
		ft_bzero(v->to_print, BUFFLEN + 1);
	}
}
