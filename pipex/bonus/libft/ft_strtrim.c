/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:34:30 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/13 17:21:26 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_leftcheck(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_inset(s1[i], set) == 1)
		i++;
	return (i);
}

static int	ft_rightcheck(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (ft_inset(s1[i], set) == 1)
		i--;
	if (i < 0)
		return (ft_strlen(s1));
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*tmp;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = ft_leftcheck(s1, set);
	end = ft_rightcheck(s1, set);
	if (end - start == 0 && start == (int)ft_strlen(s1))
		end--;
	tmp = malloc(((end - start) + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (start <= end)
	{
		tmp[i] = s1[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}
