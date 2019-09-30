/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:47:54 by pberge            #+#    #+#             */
/*   Updated: 2019/09/30 17:51:54 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** detaching text from string-in-parse ; appending detached to print-string
*/

int		parse_text(char **s, char **to_print, int vlen)
{
	int		slen;
	char	*tmp;

	slen = 0;
	while ((*s)[slen] != '%' && (*s)[slen] != '\0')
		slen++;
	ft_strncat(*to_print + vlen, *s, slen);
	*s += slen;
	return (slen);
}
