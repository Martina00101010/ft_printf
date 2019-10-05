/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:11:18 by koparker          #+#    #+#             */
/*   Updated: 2019/10/05 08:08:50 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

#include <stdio.h>

double	ft_f(t_vaio *v, t_flags *flg)
{
	return (1.0);
}

char	*ft_strndup(const char *s1, unsigned char n)
{
	int		i;
	char	*s2;

	i = 0;
	if (!(s2 = (char *)malloc(sizeof(*s2) * (n + 1))))
		return (NULL);
	while (n != 0 && s1[i])
	{
		s2[i] = s1[i];
		i++;
		n--;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_join_str(const char *s1, const char *s2, const char c)
{
	char	*res;
	size_t	len;
	size_t	s1_len;
	size_t	j;

	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2) + 1;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res = ft_strncpy(res, s1, s1_len);
	res[s1_len] = c;
	j = 0;
	while (++s1_len <= len)
		res[s1_len] = s2[j++];
	res[++s1_len] = '\0';
	return (res);
}

char	*floats(char *str, int preci)
{
	char	*tmp;
	char	*nbr;
	char	*frac;
	int		frac_len;
	char	*fr;

	if ((tmp = ft_strchr(str, '.')) == NULL)
		return (ft_strdup(str));
	nbr = ft_strndup(str, tmp - str);
	frac = ft_strdup(tmp + 1);
	frac_len = ft_strlen(frac);
	fr = ft_memset(fr, '0', preci + 1);
	fr[preci] = '\0';
	int i = -1;
	if (frac_len < preci)
	{
		while (++i < frac_len)
		{
			if (frac[i] != '0')
				fr[i] = frac[i];
		}
		printf("final number preci >= frac_len = %s . %s\n", nbr, fr);
	}
	else if (frac_len > preci)
	{
		i = preci - 1;
		if (frac[preci] > '4')
		{
			if (frac[preci - 1] != '9')
				frac[preci - 1] = ((frac[preci - 1] - '0') + 1) + '0';
			else
				frac[i] = '1';
		}
		printf("i =========== %d\n", i);
		if (i == -1)
		{
			nbr[ft_strlen(nbr) - 1] += 1;
		}
		fr = ft_strndup(frac, preci);
		fr = ft_join_str(nbr, fr, '.');
		printf("final number preci < frac_len = %s\n", fr);
	}
	return (fr);
}
