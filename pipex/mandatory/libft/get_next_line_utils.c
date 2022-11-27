/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:59:32 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/20 02:40:01 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_get_calloc(size_t nmemb, size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (size == 0 || nmemb == 0)
		return (malloc(1));
	if (nmemb * size / nmemb != size || size > INT_MAX || nmemb > INT_MAX)
		return (NULL);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
	{
		tmp[i] = '\0';
		i++;
	}
	return ((void *)tmp);
}

size_t	ft_get_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_get_strchr(char *s, int c)
{
	unsigned int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s);
		i++;
	}
	return (NULL);
}

static char	*ft_setstr(char *str)
{
	if (!str)
	{
		str = ft_calloc(1, 1);
		str[0] = 0;
	}
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_get_strjoin(char *s1, char *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	s1 = ft_setstr(s1);
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[sizetotal] = 0;
	free(s1);
	return (res);
}
