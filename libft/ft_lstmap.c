/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 13:14:08 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 11:25:58 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = (*f)(lst);
		if (first)
		{
			current->next = new;
			current = current->next;
		}
		else
		{
			first = new;
			current = first;
		}
		lst = lst->next;
	}
	return (first);
}
