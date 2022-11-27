/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:29:19 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/14 23:22:48 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (size + src_len);
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size == 0 || i > size)
		return (size + j);
	if (!src)
		return (i);
	j = 0;
	size -= 1;
	while (src[j] && (i + j < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + src_len);
}
