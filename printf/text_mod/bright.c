/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bright.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:00:34 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/31 06:00:36 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	bt_backround(const char *str, int *i)
{
	if (str[*i] == 'K')
		ft_putstr("\033[100m");
	else if (str[*i] == 'R')
		ft_putstr("\033[101m");
	else if (str[*i] == 'G')
		ft_putstr("\033[102m");
	else if (str[*i] == 'Y')
		ft_putstr("\033[103m");
	else if (str[*i] == 'B')
		ft_putstr("\033[104m");
	else if (str[*i] == 'P')
		ft_putstr("\033[105m");
	else if (str[*i] == 'C')
		ft_putstr("\033[106m");
	else if (str[*i] == 'W')
		ft_putstr("\033[107m");
}

void	bright(const char *str, int *i)
{
	*i += 1;
	if (str[*i] == 'k')
		ft_putstr("\033[90m");
	else if (str[*i] == 'r')
		ft_putstr("\033[91m");
	else if (str[*i] == 'g')
		ft_putstr("\033[92m");
	else if (str[*i] == 'y')
		ft_putstr("\033[93m");
	else if (str[*i] == 'b')
		ft_putstr("\033[94m");
	else if (str[*i] == 'p')
		ft_putstr("\033[95m");
	else if (str[*i] == 'c')
		ft_putstr("\033[96m");
	else if (str[*i] == 'w')
		ft_putstr("\033[97m");
	if (str[*i] && ft_strchr("krgybpcw", str[*i]))
		*i += 1;
	else if (str[*i] && ft_strchr("KRGYBPCW", str[*i]))
	{
		bt_backround(str, i);
		*i += 1;
	}
}
