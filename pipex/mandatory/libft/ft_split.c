/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:38:13 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/10 16:19:59 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			nb++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (nb);
}

static int	ft_countchar(const char *s, char c, int j)
{
	int	i;

	i = 0;
	while (s[i + j] != c && s[i + j] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	str = ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i] != '\0'))
		{
			str[j] = ft_substr(s, i, ft_countchar(s, c, i));
			if (!str[j])
				return (NULL);
			i = i + ft_countchar(s, c, i);
			j++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (str);
}
