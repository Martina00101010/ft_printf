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
//	long long	a;
//
//	a = LLMIN;
//	printf("%lli\n", LLMIN);
//	printf("|%i\n", printf("%*d", -5, 42));
//	printf("|%i\n", ft_printf("%lli", a));
	ft_printf("%x", 21);
	return (0);
}
