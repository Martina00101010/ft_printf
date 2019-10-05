/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:43:04 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 09:58:58 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** parsing length modifiers
*/

static void	hh_h_ll_l(char **s, char *length)
{
	int	len;

	len = 0;
	if (**s == 'h' && *(*s + 1) == 'h')
		*length |= HHMOD;
	else if (**s == 'h')
		*length |= HMOD;
	else if (**s == 'l' && *(*s + 1) == 'l')
		*length |= LLMOD;
	else if (**s == 'l')
		*length |= LMOD;
	else if (**s == 'L')
		*length |= BIGL;
	if (*length & HHMOD || *length & LLMOD)
		(*s) += 2;
	else if (*length & HMOD || *length & LMOD || *length & BIGL)
		(*s)++;
}

/*
** switch on flags from format string
*/

static char	switch_flag(char **s)
{
	char	flags;

	flags = 0;
	while (**s == '#' || **s == '0' || **s == ' ' ||
			**s == '-' || **s == '+')
	{
		if (**s == '#')
			flags |= SHARP;
		if (**s == '0')
			flags |= ZERO;
		if (**s == ' ')
			flags |= SPACE;
		if (**s == '-')
			flags |= MINUS;
		if (**s == '+')
			flags |= PLUS;
		(*s)++;
	}
	return (flags);
}

static void	ft_preci(char **s, va_list ap, t_flags *flg)
{
	(*s)++;
	flg->flags |= PRECISION;
	if (**s == '*')
	{
		flg->preci = va_arg(ap, int);
		if (flg->preci < 0)
		{
			flg->preci = 0;
			flg->flags -= PRECISION;
		}
		(*s)++;
	}
	else
	{
		flg->preci = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			(*s)++;
	}
}

static void	ft_width(char **s, va_list ap, t_flags *flg)
{
	if (**s == '*')
	{
		flg->width = va_arg(ap, int);
		if (flg->width < 0)
		{
			flg->width *= -1;
			flg->flags |= MINUS;
		}
		(*s)++;
	}
	else
	{
		flg->width = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			(*s)++;
	}
}

/*
**	get flags:
**		# 0 space - +
**		width, also by wildcard (*)
**		precision, also by wildcard (*)
**		hh h ll l L
*/

t_flags		parse_flags(char **s, va_list ap)
{
	char	*ptr;
	t_flags	flg;

	ft_memset((void *)&flg, 0, sizeof(t_flags));
	if ((ptr = ft_strchr(*s, '$')))
	{
		flg.param = ft_atoi(*s);
		*s += ptr - *s + 1;
	}
	flg.flags = switch_flag(s);
	ft_width(s, ap, &flg);
	if (**s == '.')
		ft_preci(s, ap, &flg);
	hh_h_ll_l(s, &flg.length);
	return (flg);
}
