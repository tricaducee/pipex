/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:18:35 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 21:17:51 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fds(int **fd)
{
	while (*fd)
	{
		if ((*fd)[0] < 2)
			close((*fd)[0]);
		if ((*fd)[1] < 2)
			close((*fd)[1]);
		fd++;
	}
}