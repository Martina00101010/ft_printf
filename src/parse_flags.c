/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:43:04 by pberge            #+#    #+#             */
/*   Updated: 2019/10/03 02:38:49 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** parsing length modifiers
*/

static void	hh_h_ll_l(char **s, t_flags *flg)
{
	int	len;

	len = 0;
	if (**s == 'h' && *(*s + 1) == 'h')
		flg->length |= HHMOD;
	else if (**s == 'h')
		flg->length |= HMOD;
	else if (**s == 'l' && *(*s + 1) == 'l')
		flg->length |= LLMOD;
	else if (**s == 'l')
		flg->length |= LMOD;
	else if (**s == 'L')
		flg->length |= BIGL;
	if (flg->length & HHMOD || flg->length & LLMOD)
		(*s) += 2;
	else if (flg->length & HMOD || flg->length & LMOD || flg->length & BIGL)
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

/*
**  skip dollar
**  ft_atoi <- width
**  skip dot
**  ft_atoi <- length
*/

t_flags		parse_flags(char **s)
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
	if ((flg.width = ft_atoi(*s)))
		while (**s >= '0' && **s <= '9')
			(*s)++;
	if (**s == '.')
	{
		(*s)++;
		flg.flags |= PRECISION;
		flg.preci = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			(*s)++;
	}
	hh_h_ll_l(s, &flg);
	return (flg);
}
