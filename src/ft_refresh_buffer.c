/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:20:04 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 19:10:08 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

/*
** refresh buffer if there is no space left
*/

void	ft_refresh_buffer(t_vaio *v, int output_len)
{
//	printf("%i!\n", BUFFLEN - v->len - output_len);
	if (BUFFLEN - v->len - output_len < 0)
	{
		write(1, v->to_print, v->len);
		ft_bzero(v->to_print, BUFFLEN + 1);
		v->ret_val += v->len;
		v->len = 0;
	}
//	printf("%i!\n", BUFFLEN - v->len - output_len);
}
