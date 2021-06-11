/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:27:52 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/10 18:44:27 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex
{
	char	*file_in;
	char	*cmd1;
	char	*cmd2;
	char	*file_out;
	int		fd[2];
}				t_pipex;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*take_path(char *s);
void	exec_exec(char **cmd, char *s);
int		count_tp(char *s);
void	redirect_output(t_pipex pipex, char **env, int in);
void	to_exec(char *s, char **env);
void	pipex_(t_pipex pipex, char **env);
char	*just_name(char *s);
void	free_pipex(t_pipex pipex);

#endif
