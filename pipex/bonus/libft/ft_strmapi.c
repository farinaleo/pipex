/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:22:15 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/13 17:43:08 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	tmp = ft_strdup(s);
	if (!tmp)
		return (NULL);
	while (s[i] != '\0')
	{
		tmp[i] = f(i, tmp[i]);
		i++;
	}
	return (tmp);
}
