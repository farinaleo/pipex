/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:22:10 by nskiba            #+#    #+#             */
/*   Updated: 2022/11/16 16:15:02 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!lst)
		return (NULL);
	tmp = malloc(sizeof(t_list));
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		i++;
	}
	return (tmp);
}
