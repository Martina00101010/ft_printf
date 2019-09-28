/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/09/28 20:01:12 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libftprintf.h"
/*
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
*/
int		main(void)
{
	int	d;

	d = 878023;
//	printf("%i", d);
//	printf("\n");
	ft_printf("%s %s %s", "this", "is", "a");
	return (0);
}
