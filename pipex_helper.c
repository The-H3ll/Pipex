/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:23:02 by molabhai          #+#    #+#             */
/*   Updated: 2021/06/08 16:23:03 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	part_num(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	if (s[0] != '\0')
		j++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

static int	word_num(char const *s, char c, int i)
{
	int	j;

	j = i;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i - j);
}

static char	**fill(char const *s, char c, int i, char **str)
{
	int	p;
	int	l;
	int	k;
	int	j;

	p = 0;
	l = 0;
	while (p < i)
	{
		while (s[l] == c)
			l++;
		if (s[l] == '\0')
			break ;
		k = word_num(s, c, l);
		str[p] = (char *)calloc((k + 1), sizeof(char));
		if (!str[p])
			return (NULL);
		j = 0;
		while (j < k && s[l] != c)
			str[p][j++] = s[l++];
		str[p][j] = '\0';
		p++;
	}
	str[p] = NULL;
	return (str);
}

static char	**free_all(char **s, int pos)
{
	while (pos > 0)
	{
		free(s[pos]);
		pos--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = part_num(s, c);
	str = (char **)calloc((i + 4), sizeof(char *));
	if (!str)
		return (NULL);
	str = fill(s, c, i, str);
	if (!str)
		return (str = free_all(str, i));
	return (str);
}
