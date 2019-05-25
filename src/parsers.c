/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:35:59 by pberge            #+#    #+#             */
/*   Updated: 2019/05/25 16:02:08 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

/*
**  ft_atoi <- param num
**  skip dollar
**  consider filling flag
**  ft_atoi <- width
**  skip dot
**  ft_atoi <- length
*/

char	switch_flag(char *s)
{
	char	flags;

	flags = 0;
	if (*s == '#')
		flags |= 1 << 0;
	if (*s == '0')
		flags |= 1 << 1;
	if (*s == ' ')
		flags |= 1 << 2;
	if (*s == '-')
		flags |= 1 << 3;
	if (*s == '+')
		flags |= 1 << 4;
	if (*s == '%')
		flags |= 1 << 5;
	return (flags);
}

int		parse_flags(char **s)
{
	int		len;
	int		param;
	char	*ptr;
	int		fill_flag;
	int		width;
	int		length;

	if ((ptr = ft_strchr(*s, '$')))
	{
		param = ft_atoi(*s);
		*s += ptr - *s + 1;
	}
	len = 0;
	return (0);
}

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
