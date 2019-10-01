/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:32:01 by pberge            #+#    #+#             */
/*   Updated: 2019/10/01 05:40:17 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

# define BUFFLEN 1023
# define SHARP 1
# define ZERO 1 << 1
# define SPACE 1 << 2
# define MINUS 1 << 3
# define PLUS 1 << 4
# define CAPITAL_HEX 1 << 5
# define PRECISION 1 << 7

# define HHMOD 1
# define HMOD 1 << 1
# define LLMOD 1 << 2
# define LMOD 1 << 3

typedef struct		s_output
{
	int		len;
	int		preci_zero;
	int		sign;
	int		num_sp;
	int		sp_flg;
	char	*number;
	char	sym;
}					t_output;

typedef struct		s_flags
{
	int		param;
	int		width;
	int		preci;
	char	length;
	char	flags;
}					t_flags;

typedef struct		s_vaio
{
	va_list	ap;
	char	*to_print;
	int		len;
}					t_vaio;

typedef int (*func_ptr[10])(t_vaio *, t_flags *);

/*
** parsers of flags
*/

void				parse_length(char **s, t_flags *flg);
char				switch_flag(char **s);
t_flags				parse_flags(char **s);

/*
** parsers of conversion specifiers
*/

int					parse_text(char **s, char **to_print, int vlen);
int					parse_string(t_vaio *v, t_flags *flg);
int					parse_percent(t_vaio *v, t_flags *flg);
int					parse_int(t_vaio *v, t_flags *flg);
int					parse_octal(t_vaio *v, t_flags *flg);
int					parse_upper_hex(t_vaio *v, t_flags *flg);
int					parse_lower_hex(t_vaio *v, t_flags *flg);
int					parse_unsigned(t_vaio *v, t_flags *flg);
int					parse_char(t_vaio *v, t_flags *flg);
int					parse_pointer(t_vaio *v, t_flags *flg);

/*
** error handlers
*/

void				ft_memory_error(void *allocated);
void				ft_the_end(t_vaio *v);

/*
** additional functions
*/

unsigned long long	get_oux_number(va_list ap, char length);
void				x_align_left(t_flags *flg, t_output out, char *to_print);
void				x_align_right(t_flags *flg, t_output out, char *to_print);
char				*ft_xtoa(unsigned long long xparam, char capital);
int					ft_printf(char *s, ...);

#endif
