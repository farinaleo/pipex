/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:02:26 by nskiba            #+#    #+#             */
/*   Updated: 2022/11/16 16:17:59 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_setline(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str [i] != '\0' && str [i] != '\n')
		i++;
	tmp = ft_calloc(i + 2, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] != '\0' && str[i] == '\n')
		tmp[i] = '\n';
	return (tmp);
}

char	*ft_read(int fd, char *str)
{
	char	*tmp;
	int		nb_read;

	nb_read = 1;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (nb_read > 0)
	{
		nb_read = read(fd, tmp, BUFFER_SIZE);
		if (nb_read == -1)
			free(tmp);
		if (nb_read == -1)
			return (NULL);
		tmp[nb_read] = 0;
		str = ft_strjoin(str, tmp);
		if (!str)
			free(tmp);
		if (!str)
			return (NULL);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (str);
}

char	*ft_next(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str [i] != '\0' && str [i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i += 1;
	while (str[i + j] != '\0')
	{
		tmp[j] = str[i + j];
		j++;
	}
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str || !(ft_strchr(str, '\n')))
	{
		str = ft_read(fd, str);
		if (!str)
			return (NULL);
	}
	line = ft_setline(str);
	str = ft_next(str);
	return (line);
}
