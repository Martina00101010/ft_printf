/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 01:01:02 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 20:21:06 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

char			*ft_utoa(unsigned long long uparam)
{
	unsigned long long	tmp;
	char				*u;
	int					len;

	len = 0;
	tmp = uparam;
	while (tmp > 0)
	{
		len++;
		tmp /= 10;
	}
	len = (uparam == 0) ? 1 : len;
	if (!(u = ft_strnew(len + 1)))
		return (NULL);
	while (--len > -1)
	{
		u[len] = uparam % 10 + '0';
		uparam /= 10;
	}
	return (u);
}

static void		u_align_right(t_flags *flg, t_output *out, char *to_print)
{
	int		p;

	if (flg->flags & ZERO && !(flg->flags & PRECISION))
		flg->preci = flg->width - out->len;
	out->num_sp = flg->width - flg->preci - out->len;
	ft_memset(to_print, ' ', out->num_sp);
	p = out->num_sp;
	ft_memset(to_print + p, '0', flg->preci);
	p += flg->preci;
	if (!out->preci_zero)
		ft_strcat(to_print + p, out->number);
}

static void		u_align_left(t_flags *flg, t_output *out, char *to_print)
{
	int		p;

	out->num_sp = flg->width - flg->preci - out->len;
	ft_memset(to_print, '0', flg->preci);
	p = flg->preci;
	if (!out->preci_zero)
		ft_strcat(to_print + p, out->number);
	p += out->len;
	ft_memset(to_print + p, ' ', out->num_sp);
}

static t_output	u_output_structure(t_flags *flg, unsigned long long uparam)
{
	t_output	out;

	ft_bzero(&out, sizeof(t_output));
	if (uparam == 0 && flg->flags & PRECISION && flg->preci == 0)
		out.preci_zero = 1;
	out.number = ft_utoa(uparam);
	out.len = out.preci_zero ? 0 : ft_strlen(out.number);
	flg->width = (flg->width < out.len) ? out.len : flg->width;
	flg->width = (flg->width < flg->preci) ? flg->preci : flg->width;
	flg->preci = (flg->preci > out.len) ? flg->preci - out.len : 0;
	return (out);
}

int				ft_u(t_vaio *v, t_flags *flg)
{
	unsigned long long	uparam;
	t_output			out;

	uparam = get_oux_number(v->ap, flg->length);
	out = u_output_structure(flg, uparam);
	if (out.number == NULL)
		ft_the_end(v);
	ft_refresh_buffer(v, flg->width);
	if (flg->flags & MINUS)
		u_align_left(flg, &out, v->to_print + v->len);
	else
		u_align_right(flg, &out, v->to_print + v->len);
	free(out.number);
	return (flg->width);
}
