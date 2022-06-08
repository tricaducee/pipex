/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:53:07 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/08 20:12:06 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	exit_error(char *str)
{
	ft_printf ("#rERROR#0 : [#/r%s#0]", str);
	exit (EXIT_FAILURE);
}
