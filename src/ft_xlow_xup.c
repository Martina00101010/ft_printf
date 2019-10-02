/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlow_xup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:44:20 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 20:46:30 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_x_up(t_vaio *v, t_flags *flg)
{
	flg->flags |= CAPITAL_HEX;
	return (ft_x(v, flg));
}

int				ft_x_low(t_vaio *v, t_flags *flg)
{
	return (ft_x(v, flg));
}
