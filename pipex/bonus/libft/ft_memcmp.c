/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:50:17 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/03 22:03:38 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned int	j;
	unsigned long	i;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	i = n;
	j = 0;
	while (i > 0)
	{
		if (p1[j] != p2[j])
			return (p1[j] - p2[j]);
		j++;
		i--;
	}
	return (0);
}
