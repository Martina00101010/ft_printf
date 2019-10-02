/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:10:21 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 19:09:43 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	ft_memory_error(void *allocated)
{
	if (allocated == NULL)
		exit(1);
}

void	ft_the_end(t_vaio *v)
{
	free(v->to_print);
	exit(1);
}
