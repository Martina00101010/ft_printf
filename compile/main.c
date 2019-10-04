/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/10/04 16:39:12 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

// #include <limits.h>

// void	print_bits(int b, int size)
// {
// 	int	n;

// 	while (--size > -1)
// 	{
// 		n = 8;
// 		while (--n > -1)
// 			printf("%c", b & 1 << (n + size * 8) ? '1' : '0');
// 		printf(" ");
// 	}
// }

int		main(void)
{
	char *str;
	char *tmp;
	
	str = "123.0094";
	tmp = floats(str, 2);
	ft_putendl(tmp);
	// int		i;

	// 	printf("|%i", printf("%%"));
	// printf("\n");
	// printf("|%i", ft_printf("%%"));

	// printf("\n 123.994457 .3 -> %.3f\n", 123.994457);
	// ft_putendl(floats("123.994457", 3));
	// printf("\n 123.996 .0 -> %.0f\n", 123.996);
	// ft_putendl(floats("123.996", 0));
	// printf("\n 123.994 .1 -> %.1f\n", 123.994);
	// ft_putendl(floats("123.994", 1));
	// printf("\n 123.0997 .2 -> %.2f\n", 123.0997);
	// ft_putendl(floats("123.0997", 2));
	//  printf("\n 123.9997 .2 -> %.2f\n", 123.0094);
	//ft_putendl(floats("123.0094", 2));
	
//	ft_printf("%x", 0x21);
//	print_bits(ui, sizeof(unsigned int));
	printf("HERE\n");
	return (0);
}
