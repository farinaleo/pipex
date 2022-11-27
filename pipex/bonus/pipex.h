/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42anougleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:50:11 by nskiba            #+#    #+#             */
/*   Updated: 2022/11/23 23:43:20 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <termios.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_fd
{
	int	fdin;
	int	fdout;
	int	pipefd[2];
	int	status_in;
	int	status_out;
	int	status_pipe;
}	t_fd;

// void	ft_perror(char *str);
void	ft_error(char *str);
// void	ft_free_split(char **str);
// char	*ft_path(char **env);
// char	*ft_strjoin_path(char *path, char *cmd_name);
// char	*ft_checkcmd(char *cmd, char *path);
// void	ft_closepipe(t_fd pipex);
// char	*ft_check_path(char *cmd, char *path);

#endif