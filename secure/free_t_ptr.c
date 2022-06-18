/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:57:35 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/18 12:58:40 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/pipex.h"

void	free_t_ptr(t_ptr *tabs)
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
}
