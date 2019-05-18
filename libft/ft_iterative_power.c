/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:39:15 by pberge            #+#    #+#             */
/*   Updated: 2018/12/14 19:00:45 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int p;

	p = 1;
	if (power == 0 && nb == 0)
		return (1);
	else if (power < 0 || nb == 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		while (power > 0)
		{
			p = p * nb;
			power--;
		}
		return (p);
	}
}
