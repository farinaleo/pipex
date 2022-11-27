/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:33:02 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/14 13:14:16 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_correctlen(int stringlen, int start, int len)
{
	if (start > stringlen)
		return (0);
	if (len >= stringlen - start + 1 && stringlen - start + 1 >= 0)
		return (stringlen - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				strl;
	char			*tmp;

	i = 0;
	if (!s)
		return (NULL);
	strl = ft_strlen(s);
	len = ft_correctlen(strl, start, len);
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + i] != '\0' && i < len)
		{
			tmp[i] = s[start + i];
			i++;
		}
	}
	tmp[i] = '\0';
	return (tmp);
}
