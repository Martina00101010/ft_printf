/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:55 by pberge            #+#    #+#             */
/*   Updated: 2019/05/12 19:14:48 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int		main(void)
{
	char	*s;

	s = "Printing variable";
//	ft_printf("%s\n", s);
	   printf("%-21s\n", s);
	return (0);
}
