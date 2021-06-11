/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:25:58 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/10 16:26:00 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_output(t_pipex pipex, char **env, int in)
{
	int		fd;
	pid_t	pid;

	fd = open(pipex.file_out, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd == -1)
		write(2, strerror((errno)), ft_strlen(strerror((errno))));
	pid = fork();
	if (pid == 0)
	{
		dup2(in, 0);
		close(in);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		to_exec(pipex.cmd2, env);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, NULL, WUNTRACED);
	close(fd);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
}

void	pipe_(int fd, t_pipex pipex, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close(pipex.fd[0]);
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			exit(EXIT_FAILURE);
		}
		close(fd);
		if (dup2(pipex.fd[1], 1) == -1)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			exit(EXIT_FAILURE);
		}
		close(pipex.fd[1]);
		if (fd != -1)
			to_exec(pipex.cmd1, env);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, NULL, WUNTRACED);
}

void	pipex_(t_pipex pipex, char **env)
{
	int		save_stdin;
	int		in;
	int		fd;

	save_stdin = dup(STDIN_FILENO);
	fd = open(pipex.file_in, O_RDWR, S_IRWXU);
	if (fd == -1)
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	pipe(pipex.fd);
	pipe_(fd, pipex, env);
	in = pipex.fd[0];
	close(pipex.fd[1]);
	redirect_output(pipex, env, in);
	dup2(save_stdin, 0);
	close(save_stdin);
	close(in);
}

void	to_exec(char *s, char **env)
{
	char	*path;
	char	**cmd;
	int		i;

	i = 0;
	path = NULL;
	while (env[i] != NULL)
	{
		if (strcmp(just_name(env[i]), "PATH") == 0)
		{
			path = take_path(env[i]);
			break ;
		}
		i += 1;
	}
	cmd = ft_split(path, ':');
	exec_exec(cmd, s);
	if (path)
	{
		free(path);
		path = NULL;
	}
}

void	free_pipex(t_pipex pipex)
{
	free(pipex.cmd1);
	free(pipex.cmd2);
	free(pipex.file_out);
	free(pipex.file_in);
}
