/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:03:32 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/13 11:27:24 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	i = ft_strlen(s);
	if (i >= 0)
	{
		while (i >= 0)
		{
			if (s[i] == (char)c)
				return ((char *)s + i);
			i--;
		}
	}
	return (NULL);
}
