/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:57:53 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/21 12:57:54 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;

	if (lst == NULL)
		return (NULL);
	ret = ft_lstnew(f(lst->content));
	if (!ret)
		return (0);
	cur = ret;
	lst = lst->next;
	while (lst)
	{
		cur->next = ft_lstnew(f(lst->content));
		if (!(cur->next))
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (ret);
}
