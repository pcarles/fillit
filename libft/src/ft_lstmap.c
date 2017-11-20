/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:05:47 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/14 11:17:38 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	newlst = ft_lstnew(tmp->content, tmp->content_size);
	if (!newlst)
		return (NULL);
	start = newlst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		newlst->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!newlst->next)
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (start);
}
