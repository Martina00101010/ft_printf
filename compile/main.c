/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/09/30 15:50:28 by pberge           ###   ########.fr       */
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
/*	unsigned long long	x;

	x = 0xFF;*/
	long long i;

	i = 17;
	   printf("|%i", printf("%7lli", i));
	printf("\n");
	printf("|%i", ft_printf("%7lli", i));
//	print_bits(o, sizeof(int));
	return (0);
}
