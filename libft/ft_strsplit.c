/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:41:09 by pberge            #+#    #+#             */
/*   Updated: 2018/12/06 23:26:43 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_free(char ***str, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free(str[0][i]);
		str[0][i++] = NULL;
	}
	free(*str);
	*str = NULL;
	return (NULL);
}

static int	word_count(char *s, char c)
{
	int	in_word;
	int	words_num;

	words_num = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 1)
			;
		else
		{
			in_word = 1;
			words_num += 1;
		}
		s++;
	}
	return (words_num);
}

static char	**fill_with_words(char **arr, char c, int words_num, char const *s)
{
	int	i;
	int	j;
	int	start;
	int	end;

	j = 0;
	i = 0;
	while (words_num--)
	{
		while ((s[i] != '\0') && (s[i] == c))
			i++;
		start = i;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
		end = i;
		if (!(arr[j] = (char *)malloc(end - start + 1)))
			return (ft_free(&arr, j));
		ft_memset(arr[j], '\0', end - start + 1);
		ft_strncpy(arr[j++], &s[start], end - start);
		i++;
	}
	if (!(arr[j] = (char*)malloc(sizeof(char) * 1)))
		return (ft_free(&arr, j));
	arr[j] = ((void *)0);
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words_num;

	if (s == NULL)
		return (NULL);
	words_num = word_count((char *)s, c);
	if (!(arr = (char**)malloc(sizeof(char *) * (words_num + 1))))
		return (0);
	if (!(arr = fill_with_words(arr, c, words_num, s)))
		return (ft_free(&arr, words_num));
	return (arr);
}
