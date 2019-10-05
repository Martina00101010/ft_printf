/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 07:07:41 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 08:26:10 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_fract(long double fract, int preci)
{
	char		*f;
	int			len;

	if (!(f = ft_strnew(preci + 1)))
		return (NULL);
	len = -1;
	while (++len < preci + 1)
	{
		fract *= 10;
		f[len] = ((long long)fract) % 10 + '0';
	}
	return (f);
}

static void	ft_shift(char *f)
{
	char	a;
	char	b;

	a = '1';
	while (*f)
	{
		b = *f;
		*f = a;
		a = b;
		f++;
	}
	*(f - 1) = '0';
}

static void	ft_fract_end(char *f, int size)
{
	if (size == -1)
	{
		ft_shift(f);
		return ;
	}
	else if (f[size + 1] < '5')
		f[size + 1] = 0;
	else
	{
		if (f[size] < '9')
		{
			f[size] += 1;
			f[size + 1] = 0;
		}
		else
		{
			ft_fract_end(f, size - 1);
			f[size] = f[size] == '1' ? '1' : '0';
			f[size + 1] = f[size + 1] != '0' ? 0 : '0';
		}
	}
}

char		*ft_ftoa(long double fparam, int preci)
{
	long long	intgr;
	char		*f;
	char		*tmp;
	int			ilen;

	intgr = (long long)fparam;
	tmp = ft_itoa_unsigned(intgr);
	ilen = ft_strlen(tmp);
	if (!(f = ft_strnew(ilen + preci + 1)))
		return (NULL);
	ft_strcat(f, tmp);
	tmp = ft_fract(fparam - (long long)fparam, preci);
	ft_strcat(f + ilen, tmp);
	ft_fract_end(f, ilen + preci - 1);
	return (f);
}
