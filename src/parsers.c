/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:35:59 by pberge            #+#    #+#             */
/*   Updated: 2019/06/08 15:42:55 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdlib.h>
#include <stdarg.h>

/*
** taking string from va list ; applying flags to string
*/

int		parse_string(t_vaio *v, t_flags flg)
{
	char	*sparam;
	int		slen;
	int		cpylen;
	char	*tmp;

	sparam = va_arg(v->ap, char *);
	slen = ft_strlen(sparam);
	cpylen = flg.width > slen ? flg.width : slen;
	tmp = v->to_print;
	v->to_print = ft_strnew(v->len + cpylen);
	ft_strcat(v->to_print, tmp);
	free(tmp);
	if ((flg.flags & 1 << 7)/* && flg.precision < slen*/)
		slen = flg.precision < slen ? flg.precision : slen;
	if (flg.flags & 1 << 3) // minus flag found
	{
		ft_strncat(v->to_print, sparam, slen);
		ft_memset(v->to_print + v->len + slen, ' ', cpylen - slen);
	}
	else
		ft_strrcpy(v->to_print + v->len + cpylen - 1, sparam + slen - 1, slen);
	return (cpylen);
}
