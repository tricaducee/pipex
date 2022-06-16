/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdin_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:38:51 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 21:39:41 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fdin_out(int fdin, int fdout, t_ptr *tabs)
{
	if (dup2(fdin, STDIN_FILENO) == -1)
		exit_error(errno, "Dup2", tabs);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		exit_error(errno, "Dup2", tabs);
}

void	close2(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
