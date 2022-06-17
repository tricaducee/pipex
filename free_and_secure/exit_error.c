/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:53:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 21:25:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exit_error(int errnum, char *str, t_ptr *tabs)
{
	if (tabs->fd)
	{
		close_fds(tabs->fd);
		free_int_fd(tabs->fd);
	}
	if (tabs->path)
		free_strs(tabs->path);
	if (tabs->command)
		free_strs(tabs->command);
	if (tabs->heredoc)
	{
		free(tabs->heredoc);
		tabs->heredoc = NULL;
	}
	ft_printfd(2, "#rERROR#0 : [#/r%s #0:#/r %s#0]\n", str, strerror(errnum));
	exit (errnum);
}
