/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:00:47 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/31 06:00:49 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	flags_text(const char *str, int *i)
{
	while (str[*i] && ft_strchr("+/-_*[O0", str[*i]))
	{
		if (str[*i] == '+')
			ft_putstr("\033[1m");
		else if (str[*i] == '/')
			ft_putstr("\033[3m");
		else if (str[*i] == '-')
			ft_putstr("\033[9m");
		else if (str[*i] == '_')
			ft_putstr("\033[4m");
		else if (str[*i] == '[')
			ft_putstr("\033[51m");
		else if (str[*i] == 'O')
			ft_putstr("\033[52m");
		else if (str[*i] == '0')
			ft_putstr("\033[0m");
		else if (str[*i] == '*')
			bright(str, i);
		if (str[*i] && ft_strchr("+/-_*[O0", str[*i]))
			*i += 1;
	}
}
