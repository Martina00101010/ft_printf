/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/09/21 12:10:30 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libftprintf.h"
#include "libft.h"

#include <string.h>

int		main(void)
{
/*	char *s = "%+21.15i";
	int	integer = 123456789;
	printf("\t%i", printf(s, integer));
	printf("\t%i", ft_printf(s, integer));*/
	
//	printf("%05i", 43);
//	printf("\n");
//	printf("%08.5i", 34);

	ft_printf("%05i", 43);
	ft_putchar('\n');
	ft_printf("%08.5i", 34);

	//printf("%i", printf("this %i num", -267));
	//ft_printf("this %i num", -267);

	//printf("\t%i", printf("%21.12i|", 123456789));
//	printf("\n");
//	printf("\t%i", ft_printf("%15.20i", 123456789));
	//ft_printf("%-21.12i|", 123456789);

//	ft_printf(s, integer);
//	printf("\n");
//	printf(s, integer);

//	printf("\n%i\n", printf("%s", "abc"));
/*	printf("|%d\n", printf("%-5%"));
	printf("|%d", ft_printf("%-5%"));*/
/*	short		si;
	int			i;
	signed char	sc;

	sc = 1;
	i = 12345;
	si = 12345;
	printf("%hi %hhi\n", si, sc);
*/
/*	char	*s;
	char	*parse;

	parse = "%021.5s";
	s = "0123456789";
//	s = NULL;
	printf("%s\n", parse);
	printf("|\t%i ft_printf\n", ft_printf(parse, s)); // my printf
	   printf("|\t%i printf\n", printf(parse, s));    // libc printf
*/	return (0);
}
