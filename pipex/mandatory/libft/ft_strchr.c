/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:44:10 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/04 13:23:38 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((char) c == s[i])
			return ((char *)s + i);
		i++;
	}
	if (c == s[i])
		return ((char *)s + i);
	return (NULL);
}
