/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:35:59 by pberge            #+#    #+#             */
/*   Updated: 2019/05/26 19:04:43 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdlib.h>
#include <stdarg.h>

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
	ft_strrcpy(v->to_print + v->len + cpylen, sparam + slen, slen + 1);
	return (cpylen);
}
