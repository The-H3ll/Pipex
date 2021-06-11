/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:37:04 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/08 16:37:05 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (str == NULL)
		return (str);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i += 1;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof (char) * ft_strlen(s) + 1);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}

char	*take_path(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof (char ) * count_tp(s) + 1);
	while (s[i] != '=' && s[i] != '\0')
		i += 1;
	if (s[i] == '=')
		i += 1;
	while (s[i] != '\0')
	{
		str[j] = s[i];
		j += 1;
		i += 1;
	}
	str[j] = '\0';
	return (str);
}

void	exec_exec(char **cmd, char *s)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(s, ' ');
	while (cmd[i] != NULL)
	{
		cmd[i] = ft_strjoin(cmd[i], "/");
		cmd[i] = ft_strjoin(cmd[i], split[0]);
		execve(cmd[i], split, NULL);
		i += 1;
	}
	execve(split[0], split, NULL);
	write(2, "Command not found\n", 18);
}
