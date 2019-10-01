/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/10/01 20:58:27 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

#include <limits.h>

void	print_bits(int b, int size)
{
	int	n;

	while (--size > -1)
	{
		n = 8;
		while (--n > -1)
			printf("%c", b & 1 << (n + size * 8) ? '1' : '0');
		printf(" ");
	}
}

int		main(void)
{
	int		n;
	int		*p;

	n = 42;
	p = &n;
	unsigned char c;
	c = 1;
	   printf("|%i", printf("% 2.3f", c));
	printf("\n");
	printf("|%i", ft_printf("% 2.3f", c));
//	print_bits(ui, sizeof(unsigned int));
	return (0);
}
