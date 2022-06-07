/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:15:00 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:15:07 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	rec_putnbr(unsigned int n)
{
	unsigned int	nb;

	nb = n;
	if (n > 9)
		rec_putnbr(n / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int n)
{
	int	pn;

	pn = 1;
	if (n < 0)
		pn *= -1;
	rec_putnbr(n * pn);
}
