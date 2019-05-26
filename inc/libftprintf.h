/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:32:01 by pberge            #+#    #+#             */
/*   Updated: 2019/05/26 17:17:49 by pberge           ###   ########.fr       */
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
