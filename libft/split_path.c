/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:36:38 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/08 19:44:51 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	compt_path(char *s)
{
	int	j;

	j = 0;
	while (*s)
	{
		if (*s != ':' && (!*(s + 1) || *(s + 1) == ':'))
			j++;
		s++;
	}
	return (j);
}

char	**free_tab(char **strs)
{
	while (*strs)
	{
		free(*strs);
		*strs = NULL;
		strs++;
	}
	return (NULL);
}

char	*path_and_cmd(char *path, char *cmd)
{
	int		i;
	char	*ret;

	i = ft_strlen_c(path, ':') + ft_strlen_c(cmd, ':') + 2;
	ret = malloc(i * sizeof(char));
	i = 0;
	if (!ret)
		return (NULL);
	while (*path && *path != ':')
		ret[i++] = *(path++);
	ret[i++] = '/';
	while (*cmd && *cmd != ':')
		ret[i++] = *(cmd++);
	ret[i] = 0;
	return (ret);
}

char	**split_path(char *str, char *cmd)
{
	int		i;
	char	**strs;
	int		cmd_len;

	i = 0;
	cmd_len = ft_strlen(cmd);
	strs = malloc((compt_path(str) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (*str)
	{
		strs[i] = path_and_cmd(str, cmd);
		if (!strs[i])
			return (free_tab(strs));
		str += ft_strlen_c(str, ':');
		if (*str == ':')
			str++;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
