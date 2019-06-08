/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/06/08 15:41:19 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include "libft.h"

#include <string.h>

int		main(void)
{
	char	*s;
	char	*parse;

	parse = "%.2s";
//	s = "0123456789";
	s = "this";
	printf("%s\n", parse);
	printf("|\t%i ft_printf\n", ft_printf(parse, s)); // my printf
	   printf("|\t%i printf\n", printf(parse, s));    // libc printf
	return (0);
}
