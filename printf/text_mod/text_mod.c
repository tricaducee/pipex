/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 04:58:53 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/31 04:58:56 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	backround(const char *str, int *i)
{
	if (str[*i] == 'K')
		ft_putstr("\033[40m");
	else if (str[*i] == 'R')
		ft_putstr("\033[41m");
	else if (str[*i] == 'G')
		ft_putstr("\033[42m");
	else if (str[*i] == 'Y')
		ft_putstr("\033[43m");
	else if (str[*i] == 'B')
		ft_putstr("\033[44m");
	else if (str[*i] == 'P')
		ft_putstr("\033[45m");
	else if (str[*i] == 'C')
		ft_putstr("\033[46m");
	else if (str[*i] == 'W')
		ft_putstr("\033[47m");
}

void	color(const char *str, int *i)
{
	if (str[*i] == 'k')
		ft_putstr("\033[30m");
	else if (str[*i] == 'r')
		ft_putstr("\033[31m");
	else if (str[*i] == 'g')
		ft_putstr("\033[32m");
	else if (str[*i] == 'y')
		ft_putstr("\033[33m");
	else if (str[*i] == 'b')
		ft_putstr("\033[34m");
	else if (str[*i] == 'p')
		ft_putstr("\033[35m");
	else if (str[*i] == 'c')
		ft_putstr("\033[36m");
	else if (str[*i] == 'w')
		ft_putstr("\033[37m");
}

int	text_mod(const char *str, int *i)
{
	*i += 1;
	if (str[*i] == '#')
	{
		ft_putchar('#');
		*i += 1;
		return (1);
	}
	if (str[*i] && ft_strchr("+/-_*[O0", str[*i]))
		flags_text(str, i);
	if (str[*i] && ft_strchr("krgybpcw", str[*i]))
	{
		color(str, i);
		*i += 1;
	}
	else if (str[*i] && ft_strchr("KRGYBPCW", str[*i]))
	{
		backround(str, i);
		*i += 1;
	}
	return (0);
}
	//if (str[*i] == ';')
	//	rgb(str, i);
	//else if (str[*i] == ':')
	//	eight_bit(str, i);
