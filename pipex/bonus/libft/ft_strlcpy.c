/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:44:15 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/04 00:13:24 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!(size == 0))
	{
		size -= 1;
		while (src[i] != '\0' && i < size)
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (ft_strlen(src));
}
