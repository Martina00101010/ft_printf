/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:40:36 by pberge            #+#    #+#             */
/*   Updated: 2019/01/21 23:31:54 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	if (!(head = f(lst)))
		return (NULL);
	tmp = head;
	while (lst->next != NULL)
	{
		if (!(tmp->next = f(lst->next)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
