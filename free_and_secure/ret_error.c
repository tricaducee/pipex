/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:52:00 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 13:08:07 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ret_error(char *str)
{
	ft_printfd(STDERR_FILENO, "#rERROR#0 : [#/r%s#0]\n#/r", str);
	perror(0);
	ft_printfd(STDERR_FILENO, "#0");
	return (1);
}
