/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:19:20 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/13 21:47:16 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	char	*result;

	i = 0;
	result = 0;
	if (little[i] == '\0')
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		result = ((char *) big + i);
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return (result);
			j++;
		}
	i++;
	}
	return (NULL);
}
