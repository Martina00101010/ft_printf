/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/10/03 23:48:49 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

#include <limits.h>

void	print_bits(unsigned char *b, int size)
{
	int	n;

	while (--size > -1)
	{
		n = 8;
		while (--n > -1)
			printf("%c", (b[size] & (1 << n)) ? '1' : '0');
		printf(" ");
	}
}

int		main(void)
{
	float	d;
	char	c;

	c = -1;
	d = 1.;
//	printf("%f\n", d);
//	printf("Hello world");
//		printf("|%i", printf("%f", 573.924));
//	printf("\n");
//	printf("|%i", ft_printf("%f", 573.924));

//	printf("%.5f", 573.924);
	ft_printf("%f", 573.924);
//	print_bits((unsigned char *)&d, sizeof(d));
	return (0);
}
