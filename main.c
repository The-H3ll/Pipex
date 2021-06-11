/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:15:20 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/08 15:15:21 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	init_pipex(char **av)
{
	t_pipex	pipex;

	pipex.file_in = ft_strdup(av[1]);
	pipex.cmd1 = ft_strdup(av[2]);
	pipex.cmd2 = ft_strdup(av[3]);
	pipex.file_out = ft_strdup(av[4]);
	return (pipex);
}

int	count_tp(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '=' && s[i] != '\0')
		i += 1;
	if (s[i] == '=')
		i += 1;
	while (s[i] != '\0')
	{
		i += 1;
		count += 1;
	}
	return (count);
}

int 	c_just_name(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '=' && s[i] != '\0')
	{
		i += 1;
		count += 1;
	}
	return (count);
}

char	*just_name(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) malloc(sizeof (char ) * c_just_name(s) + 1);
	while (s[i] != '=' && s[i] != '\0')
	{
		str[i] = s[i];
		i += 1;
	}
	return (str);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac == 5)
	{
		pipex = init_pipex(av);
		pipex_(pipex, env);
		free_pipex(pipex);
	}
	else
		write(2, "Usage == 'file 1' 'cmd1' 'cmd2' 'file2'\n", 40);
	return (0);
}
