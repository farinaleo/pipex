/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:42:53 by nskiba            #+#    #+#             */
/*   Updated: 2022/11/23 23:43:27 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	ft_free_split(char **str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return ;
// 	while (str[i] != NULL)
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }

// void	ft_perror(char *str)
// {
// 	perror(str);
// 	exit(1);
// }

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}
