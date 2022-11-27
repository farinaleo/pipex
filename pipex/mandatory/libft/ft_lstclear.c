/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:36:01 by nskiba            #+#    #+#             */
/*   Updated: 2022/11/16 16:17:12 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*lstdel;

	if (!lst || !del || !(*lst))
		return ;
	tmp = *lst;
	while (tmp)
	{
		lstdel = tmp;
		tmp = tmp->next;
		ft_lstdelone(lstdel, del);
	}
	*lst = 0;
}
