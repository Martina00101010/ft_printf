/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/05/26 19:03:07 by pberge           ###   ########.fr       */
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

	c = -127;
	s = "0123456789";
	printf("ret %i\n", ft_printf("ft_printf |%20s|\n", s));
//	   printf("%d\n", printf("printf    |%10.3s|  ", s));
	return (0);
}
