/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:35:47 by nskiba            #+#    #+#             */
/*   Updated: 2022/11/23 23:16:31 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_path(char *cmd, char *path)
{
	char	*tmp;
	char	*tmp2;
	char	**path_split;
	int		i;

	tmp = ft_strrchr(cmd, '/');
	path_split = ft_split(path, ':');
	i = 0;
	while (path_split[i])
	{
		tmp2 = ft_strjoin(path_split[i], tmp);
		if (ft_strncmp(tmp2, cmd, strlen(cmd)) == 0)
		{
			if (access(tmp2, F_OK) == 0)
			{
				ft_free_split(path_split);
				free(tmp2);
				return (cmd);
			}
		}
		free(tmp2);
		i++;
	}
	ft_free_split(path_split);
	return (NULL);
}

char	*ft_checkcmd(char *cmd, char *path)
{
	int		i;
	char	*tmp;
	char	**path_split;

	i = 0;
	path_split = ft_split(path, ':');
	while (path_split[i])
	{
		tmp = ft_strjoin_path(path_split[i], cmd);
		if (access(tmp, F_OK) == 0)
		{
			ft_free_split(path_split);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	ft_free_split(path_split);
	return (NULL);
}

void	ft_closepipe(t_fd pipex)
{
	if (pipex.status_in == 1)
	{
		close(pipex.fdin);
	}
	if (pipex.status_out == 1)
	{
		close(pipex.fdout);
	}
	if (pipex.status_pipe == 1)
	{
		close(pipex.pipefd[0]);
	}
	if (pipex.status_pipe == 1)
	{
		close(pipex.pipefd[1]);
	}
}

char	*ft_path(char **env)
{
	while (strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

char	*ft_strjoin_path(char *path, char *cmd_name)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path, "/");
	tmp2 = ft_strjoin(tmp, cmd_name);
	free(tmp);
	return (tmp2);
}
