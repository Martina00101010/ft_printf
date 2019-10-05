/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:32:01 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 08:41:52 by pberge           ###   ########.fr       */
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
# define BIGL 1 << 4
# define B_UNSIGNED 1 << 5

# define LLMIN 9223372036854775807LL * -1 - 1LL

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
	int		ret_val;
}					t_vaio;

# define NUMF 11

typedef int			(*t_convert[NUMF])(t_vaio *, t_flags *);

/*
** parsers of flags
*/

t_flags				parse_flags(char **s, va_list ap);

/*
** parsers of conversion specifiers
*/

int					ft_text(char **s, t_vaio *v);
int					ft_percent(t_vaio *v, t_flags *flg);
int					ft_c(t_vaio *v, t_flags *flg);
int					ft_s(t_vaio *v, t_flags *flg);
int					ft_p(t_vaio *v, t_flags *flg);
int					ft_i(t_vaio *v, t_flags *flg);
int					ft_o(t_vaio *v, t_flags *flg);
int					ft_u(t_vaio *v, t_flags *flg);
int					ft_x(t_vaio *v, t_flags *flg);
int					ft_x_low(t_vaio *v, t_flags *flg);
int					ft_x_up(t_vaio *v, t_flags *flg);
int					ft_f(t_vaio *v, t_flags *flg);

/*
** error handlers
*/

void				ft_memory_error(void *allocated);
void				ft_the_end(t_vaio *v);

/*
** additional functions
*/

char				*ft_itoa_unsigned(long long n);
char				*ft_ulltoa(unsigned long long n);
unsigned long long	get_oux_number(va_list ap, char length);
long long			get_i_number(va_list ap, char length);
void				x_align_left(t_flags *flg, t_output out, char *to_print);
void				x_align_right(t_flags *flg, t_output out, char *to_print);
char				*ft_xtoa(unsigned long long xparam, char capital);
int					ft_printf(char *s, ...);
void				ft_refresh_buffer(t_vaio *v, int output_len);
char				*ft_ftoa(long double fparam, int preci);

/*
** test
*/

char				*floats(char *str, int preci);

#endif
