/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:17:32 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:17:40 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	repeat_putc_for_d(t_flags *flags, int c)
{
	if (flags->len > flags->d
		|| (flags->point > flags->d && flags->len > flags->point))
	{
		if (flags->point > flags->d)
			repeat_putchar(c, flags->len - flags->point);
		else
			repeat_putchar(c, flags->len - flags->d);
	}
}

void	put_sign(t_flags *flags, int d)
{
	if (d >= 0 && flags->plus)
		ft_putchar('+');
	else if (d >= 0 && flags->sp)
		ft_putchar(' ');
	else if (d < 0)
		ft_putchar('-');
}

int	print_d(t_flags *flags, int d)
{
	int	c;

	flags->d = nbrlen(d, 10, flags);
	if (!flags->zero || flags->point || !flags->d)
		c = ' ';
	else
		c = '0';
	if (!flags->min && (!flags->zero || flags->point))
		repeat_putc_for_d(flags, c);
	put_sign(flags, d);
	if (!flags->min && (flags->zero && !flags->point))
		repeat_putc_for_d(flags, c);
	if (flags->point > flags->d)
		repeat_putchar('0', flags->point - flags->d);
	if (flags->d)
		ft_putnbr(d);
	if (flags->min)
		repeat_putc_for_d(flags, ' ');
	if (flags->len > flags->d && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->d)
		return (flags->point);
	return (flags->d);
}
