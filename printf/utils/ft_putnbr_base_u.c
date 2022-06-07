/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:15:16 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:15:30 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	ft_putnbr_base_u(unsigned long n, char *str, unsigned long base)
{
	unsigned int	nb;

	nb = n;
	if (n >= base)
		ft_putnbr_base_u(n / base, str, base);
	ft_putchar(str[nb % base]);
}
