/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 01:26:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 21:35:22 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipes_tab_gen(int size, t_ptr *tabs)
{
	int	i;

	i = 0;
	tabs->fd = malloc((size + 1) * sizeof(int *));
	if (!tabs->fd)
		exit_error(errno, "Malloc", tabs);
	while (i < size)
	{
		tabs->fd[i] = malloc(2 * sizeof(int));
		if (!tabs->fd[i])
			exit_error(errno, "Malloc", tabs);
		i++;
	}
	tabs->fd[i] = NULL;
	i = 1;
	while (tabs->fd[i])
	{
		if (pipe(tabs->fd[i]) == -1)
			exit_error(errno, "Pipe error", tabs);
		i++;
	}
}

void	heredoc_fd(int ac, t_ptr *tabs)
{
	heredoc_str(tabs);
	pipes_tab_gen(ac - 3, tabs);
	if (pipe(tabs->fd[0]) == -1)
		exit_error(errno, "Pipe not work", tabs);
	write(tabs->fd[0][1], tabs->heredoc, ft_strlen(tabs->heredoc));
	close(tabs->fd[0][1]);
	free(tabs->heredoc);
	tabs->heredoc = NULL;
	tabs->fd[0][1]
		= open(tabs->av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (tabs->fd[0][1] == -1)
		exit_error(errno, tabs->av[ac -1], tabs);
}

void	no_heredoc_fd(int ac, t_ptr *tabs)
{
	pipes_tab_gen(ac - 2, tabs);
	tabs->fd[0][0] = open(tabs->av[1], O_RDONLY);
	if (tabs->fd[0][0] == -1)
		exit_error(errno, tabs->av[1], tabs);
	tabs->fd[0][1] = open(tabs->av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tabs->fd[0][1] == -1)
		exit_error(errno, tabs->av[ac -1], tabs);
}

void	fd_gen(int ac, t_ptr *tabs)
{
	if (ft_strcmp("here_doc", tabs->av[1]))
		return (heredoc_fd(ac, tabs));
	return (no_heredoc_fd(ac, tabs));
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
