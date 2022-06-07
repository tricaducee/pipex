/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:15:52 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:15:58 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

void	ft_putstr_l(char *s, int len)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < len)
		write(1, s + i++, 1);
}
