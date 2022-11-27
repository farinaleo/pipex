/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:30:47 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/12 17:41:16 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(void *dest, const char *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (char *)src;
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
	return ((void *)dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	if (src < dest)
		dest = ft_reverse(dest, src, n);
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return ((void *)dest);
}
