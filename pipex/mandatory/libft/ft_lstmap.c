/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:58:24 by nskiba            #+#    #+#             */
/*   Updated: 2022/11/12 22:59:11 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_tmp;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	lst_tmp = ft_calloc(sizeof(t_list), 1);
	if (!lst_tmp)
		return (NULL);
	tmp = lst_tmp;
	while (lst)
	{
		lst_tmp->next = ft_calloc(sizeof(t_list), 1);
		if (!lst_tmp->next)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		lst_tmp->content = f(lst->content);
		lst_tmp = lst_tmp->next;
		lst = lst->next;
	}
	lst_tmp->next = NULL;
	return (tmp);
}
