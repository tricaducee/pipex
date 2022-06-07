/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:29 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:19:36 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	repeat_putc_for_x(t_flags *flags, int c)
{
	if (flags->len > flags->x
		|| (flags->point > flags->x && flags->len > flags->point))
	{
		if (flags->point > flags->x)
			repeat_putchar(c, flags->len - flags->point);
		else
			repeat_putchar(c, flags->len - flags->x);
	}
}

int	print_x(t_flags *flags, unsigned long int x)
{
	int	c;

	flags->x = u_nbrlen_base(x, 16, flags);
	if (!flags->zero || flags->point || !flags->x)
		c = ' ';
	else
		c = '0';
	if (!flags->min && (!flags->zero || flags->point))
		repeat_putc_for_x(flags, c);
	if ((x > 0 && flags->sharp) || flags->p)
		ft_putstr("0x");
	if (!flags->min && flags->zero && !flags->point)
		repeat_putc_for_x(flags, c);
	if (flags->point > flags->x)
		repeat_putchar('0', flags->point - flags->x);
	if (flags->x)
		ft_putnbr_base_u(x, "0123456789abcdef", 16);
	if (flags->min)
		repeat_putc_for_x(flags, ' ');
	if (flags->len > flags->x && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->x)
		return (flags->point);
	return (flags->x);
}
