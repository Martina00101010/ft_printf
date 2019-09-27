/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/09/27 21:27:03 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

void	print_bits(long long b, int size)
{
	int	n;

	while (--size > -1)
	{
		n = 8;
		while (--n > -1)
			printf("%c", b & 1 << n ? '1' : '0');
		printf(" ");
	}
}

int		main(void)
{
/*	signed char n;

	n = -128;
	printf("%hhi ", n);
	print_bits((long long)n, sizeof(n));*/

	signed char	n;

	n = 1;
	printf("%hhi", n);
	printf("\n");
	ft_printf("%hhi", n);
	return (0);
}
