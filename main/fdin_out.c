/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdin_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:38:51 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/18 09:52:05 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/pipex.h"

void	fdin_out(int fdin, int fdout, t_ptr *tabs)
{
	if (dup2(fdin, STDIN_FILENO) == -1)
		exit_error(errno, "Dup2 failure", tabs);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		exit_error(errno, "Dup2 failure", tabs);
}
