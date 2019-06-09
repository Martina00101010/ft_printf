/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/06/09 17:54:04 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include "libft.h"

#include <string.h>

int		main(void)
{
	printf("|%d", ft_printf("%03%"));
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
