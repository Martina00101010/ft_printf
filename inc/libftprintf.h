/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:32:01 by pberge            #+#    #+#             */
/*   Updated: 2019/09/27 14:34:27 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"

# define BUFFLEN 1023
# define SHARP 1
# define ZERO 1 << 1
# define SPACE 1 << 2
# define MINUS 1 << 3
# define PLUS 1 << 4
# define PRECISION 1 << 7

# define HHMOD 1
# define HMOD 1 << 1
# define LLMOD 1 << 2
# define LMOD 1 << 3

typedef struct	s_flags
{
	int			param;
//	int			fill_flag;
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
int		parse_int(t_vaio *v, t_flags flg);

#endif
