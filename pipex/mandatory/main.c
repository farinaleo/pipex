/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:41:41 by nskiba            #+#    #+#             */
/*   Updated: 2022/11/23 23:15:13 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_childone(char **argv, char *cmd, t_fd fds, char **env)
{
	char	**command_args;

	command_args = ft_split(argv[2], ' ');
	if (!command_args || !cmd || fds.fdin < 0 || ft_strchr(cmd, '/') == NULL)
	{
		if (command_args)
			ft_free_split(command_args);
		free(cmd);
		ft_closepipe(fds);
		exit(1);
	}
	dup2(fds.fdin, 0);
	dup2(fds.pipefd[1], 1);
	close(fds.pipefd[0]);
	close(fds.fdout);
	close(fds.fdin);
	close(fds.pipefd[1]);
	execve(cmd, command_args, env);
	ft_free_split(command_args);
	free(cmd);
	exit(128);
}

void	ft_childtwo(char **argv, char *cmd, t_fd fds, char **env)
{
	char	**command_args;

	command_args = ft_split(argv[3], ' ');
	if (!command_args || !cmd || fds.fdout < 0 || ft_strchr(cmd, '/') == NULL)
	{
		if (command_args)
			ft_free_split(command_args);
		free(cmd);
		ft_closepipe(fds);
		exit(1);
	}
	dup2(fds.fdout, 1);
	dup2(fds.pipefd[0], 0);
	close(fds.pipefd[1]);
	close(fds.fdin);
	close(fds.fdout);
	close(fds.pipefd[0]);
	execve(cmd, command_args, env);
	ft_free_split(command_args);
	free(cmd);
	exit(128);
}

char	*ft_get_cmd(char *cmd, char *path)
{
	char	*name;
	char	*command;
	char	**command_args;

	command_args = ft_split(cmd, ' ');
	name = NULL;
	if (ft_strchr(command_args[0], '/'))
	{
		command = ft_check_path(command_args[0], path);
		name = ft_strdup(command);
		if (command == NULL)
			ft_printf("%s: command not found\n", cmd);
	}
	else
	{
		command = ft_checkcmd(command_args[0], path);
		name = ft_strdup(command);
		if (command == NULL)
			ft_printf("%s: command not found\n", cmd);
		free(command);
	}
	ft_free_split(command_args);
	return (name);
}

void	ft_exec(char **argv, char **env, t_fd fds)
{
	pid_t	pid1;
	pid_t	pid2;
	char	*path;
	int		status;

	path = ft_path(env);
	if (pipe(fds.pipefd) < 0)
	{
		fds.status_pipe = 0;
		ft_perror("ERROR");
	}
	else
		fds.status_pipe = 1;
	pid1 = fork();
	if (pid1 == 0)
		ft_childone(argv, ft_get_cmd(argv[2], path), fds, env);
	pid2 = fork();
	if (pid2 == 0)
		ft_childtwo(argv, ft_get_cmd(argv[3], path), fds, env);
	ft_closepipe(fds);
	waitpid(pid1, &status, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_fd	fds;

	if (argc != 5)
		ft_error("ERROR: Invalid number of arguments\n");
	fds.fdin = open(argv[1], O_RDONLY);
	fds.status_in = 1;
	if (fds.fdin < 0)
	{
		ft_printf("%s: ", argv[1]);
		fds.status_in = 0;
		perror("");
	}
	fds.fdout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	fds.status_out = 1;
	if (fds.fdout < 0)
	{
		ft_printf("%s: ", argv[argc - 1]);
		fds.status_out = 0;
		perror("");
	}
	ft_exec(argv, env, fds);
}
