/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 10:01:53 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

//
//
//
// delete this file
//
//
//

void	print_bits(unsigned char *b, int size)
{
	int	n;

	while (--size > -1)
	{
		n = 8;
		while (--n > -1)
			printf("%c", *b & 1 << (n + size * 8) ? '1' : '0');
		printf(" ");
	}
}

int		main(void)
{
	// double a = 123.4;

	// double  b = (int)a - a;
	// if (b == 0)
	// 	printf("==0 %f", b);
	// else
	// 	printf("!=0 %f", b);

	printf("or %.10Lf\n", 23.8341375094499l);
	ft_printf("my %.10Lf\n\n", 23.8341375094499l);

	printf("or %.10Lf\n", 0.87650894255l);
	ft_printf("my %.10Lf\n\n", 0.87650894255l);

	// printf("or %.19f\n",        1.025978548534310421934);
	// ft_printf("my %.19f\n\n",        1.025978548534310421934);
	
	printf("or %.20f\n",        1.025978542436587568678);
	ft_printf("my %.20f\n\n",        1.025978542436587568678);
	
//	long long	a;
//
//	a = LLMIN;
//	printf("%lli\n", LLMIN);
//	printf("|%i\n", printf("%*d", -5, 42));
//	printf("|%i\n", ft_printf("%lli", a));
	// ft_printf("%x", 21);

	return (0);
}
