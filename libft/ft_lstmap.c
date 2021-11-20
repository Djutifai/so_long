/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:34:00 by ftassada          #+#    #+#             */
/*   Updated: 2021/04/21 16:02:11 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_elem;
	t_list	*temp;
	t_list	*temp2;

	if (!lst)
		return (NULL);
	first_elem = ft_lstnew((*f)(lst->content));
	if (!first_elem)
		return (NULL);
	temp = first_elem;
	lst = lst->next;
	while (lst)
	{
		temp2 = ft_lstnew((*f)(lst->content));
		if (!temp2)
		{
			ft_lstclear(&first_elem, del);
			return (NULL);
		}
		temp->next = temp2;
		temp = temp->next;
		lst = lst->next;
	}
	return (first_elem);
}
