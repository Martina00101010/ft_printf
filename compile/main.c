/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/05/25 16:02:11 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include "libft.h"

int		main(void)
{
	char	*s;
	char	c;

	c = -127;
	s = "0123456789";
//	s = "";
//	printf("%d\n", ft_printf("ft_printf |%s|  ", s));
	   printf("%d\n", printf("printf    |%20.3s|  ", ""));
	return (0);
}
