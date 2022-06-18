/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:53:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/18 10:36:08 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/pipex.h"

void	exit_error(int errnum, char *str, t_ptr *tabs)
{
	if (tabs->fd)
	{
		close_fds(tabs->fd);
		tabs->fd = (int **)free_tabs((void **)tabs->fd);
	}
	if (tabs->path)
		tabs->path = (char **)free_tabs((void **)tabs->path);
	if (tabs->command)
		tabs->command = (char **)free_tabs((void **)tabs->command);
	if (tabs->heredoc)
		free_and_null(&tabs->heredoc);
	tabs->on_exit = 1;
	ft_printfd(2, "#rERROR#0 : [#/r%s#0 : #/r%s#0]\n", str, strerror(errnum));
	exit (errnum);
}
