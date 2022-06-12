/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:26:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/13 01:27:39 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**pipes_tab_gen(int size)
{
	int	**ret;
	int	i;

	i = 0;
	ret = malloc((size + 1) * sizeof(int *));
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = malloc(2 * sizeof(int));
		if (!ret[i])
			return (free_tabs(ret));
		i++;
	}
	ret[i] = NULL;
	i = 1;
	while (ret[i])
	{
		if (pipe(ret[i]) == -1)
			return (free_tabs(ret));
		i++;
	}
	return (ret);
}

int	**heredoc_fd(int ac, char **av)
{
	char	*heredoc;
	int		**fd;

	heredoc = heredoc_str(av[2]);
	fd = pipes_tab_gen(ac - 3);
	if (!fd)
		return (NULL);
	pipe(fd[0]);
	write(fd[0][1], heredoc, ft_strlen(heredoc));
	close(fd[0][1]);
	free(heredoc);
	fd[0][1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd[0][1] == -1)
		return (NULL);
	return (fd);
}

int	**no_heredoc_fd(int ac, char **av)
{
	int	**fd;

	fd = pipes_tab_gen(ac - 2);
	if (!fd)
		return (NULL);
	fd[0][0] = open(av[1], O_RDONLY);
	if (fd[0][0] == -1)
		return (NULL);
	fd[0][1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[0][1] == -1)
		return (NULL);
	return (fd);
}

int	**fd_gen(int ac, char **av)
{
	if (ft_strcmp("here_doc", av[1]))
		return (heredoc_fd(ac, av));
	return (no_heredoc_fd(ac, av));
}

void	if_close_fd(int i, int **fd)
{
	if (i)
	{
		close(fd[i][0]);
		close(fd[i][1]);
	}
	else
		close(fd[i][0]);
}
