/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:24:01 by pberge            #+#    #+#             */
/*   Updated: 2019/05/28 18:37:14 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** coping string backwards. not coping \0. filling remaining with spaces
*/

char	*ft_strrcpy(char *dst, char *src, int len)
{
	while (len-- > 0)
	{
		*dst = *src;
		dst--;
		src--;
	}
	while (*dst == '\0')
	{
		*dst = ' ';
		dst--;
	}
	return (dst);
}

