/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:32:01 by pberge            #+#    #+#             */
/*   Updated: 2019/06/09 18:31:34 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_flags
{
	int			param;
	int			fill_flag;
	int			width;
	int			precision;
	char		length;
	char		flags;
}				t_flags;

typedef struct	s_vaio
{
	va_list		ap;
	char		*to_print;
	int			len;
}				t_vaio;

int		ft_printf(char *s, ...);
int		parse_string(t_vaio *v, t_flags flg);

#endif
