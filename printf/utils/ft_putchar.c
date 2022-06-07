/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:14:45 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:14:53 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	repeat_putchar(char c, int len)
{
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
}
