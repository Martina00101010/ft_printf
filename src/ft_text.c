/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:47:54 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 08:12:38 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** detaching text from string-in-parse ; appending detached to print-string
*/

int		ft_text(char **s, t_vaio *v)
{
	int		slen;

	slen = 0;
	while ((*s)[slen] != '%' && (*s)[slen] != '\0')
		slen++;
	ft_refresh_buffer(v, slen);
	ft_strncat(v->to_print + v->len, *s, slen);
	*s += slen;
	return (slen);
}
