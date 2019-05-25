/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:35:59 by pberge            #+#    #+#             */
/*   Updated: 2019/05/25 17:49:03 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

int		parse_string(va_list ap, char **to_print, int size)
{
	char	*sparam;
	int		len;
	char	*tmp;

	sparam = va_arg(ap, char *);
	len = ft_strlen(sparam);
	tmp = *to_print;
	*to_print = ft_strnew(size + len);
	ft_strcat(*to_print, tmp);
	ft_strcat(*to_print + size, sparam);
	free(tmp);
	return (len);
}
