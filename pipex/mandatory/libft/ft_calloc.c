/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:57:54 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/09 19:21:39 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (size == 0 || nmemb == 0)
		return (malloc(1));
	if (nmemb * size / nmemb != size || size > INT_MAX || nmemb > INT_MAX)
		return (NULL);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
	{
		tmp[i] = '\0';
		i++;
	}
	return ((void *)tmp);
}
