/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/05/28 18:54:43 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include "libft.h"

#include <string.h>

int		main(void)
{
	char	*s;
	char	*s1;
	int		d;
	char	c;
	char	*parse;

	parse = "|%21.0s| ";
	c = -127;
	s = "0123456789";
	printf("%i ft_printf\n", ft_printf(parse, s));
	   printf("%d printf\n", printf(parse, s));
	return (0);
}
