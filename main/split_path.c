/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:36:38 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/18 09:09:26 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/pipex.h"

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

void	split_path(char *str, t_ptr *tabs)
{
	int		i;
	int		cmd_len;

	i = 0;
	cmd_len = ft_strlen(tabs->command[0]);
	tabs->path = malloc((compt_path(str) + 1) * sizeof(char *));
	if (!tabs->path)
		exit_error(errno, "Malloc failure", tabs);
	while (*str)
	{
		tabs->path[i] = path_and_cmd(str, tabs->command[0]);
		if (!tabs->path[i])
			exit_error(errno, "Malloc failure", tabs);
		str += ft_strlen_c(str, ':');
		if (*str == ':')
			str++;
		i++;
	}
	tabs->path[i] = NULL;
}
