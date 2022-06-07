/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:11 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:18:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	repeat_putc_for_o(t_flags *flags, int c)
{
	if (flags->len > flags->o
		|| (flags->point > flags->o && flags->len > flags->point))
	{
		if (flags->point > flags->o)
			repeat_putchar(c, flags->len - flags->point);
		else
			repeat_putchar(c, flags->len - flags->o);
	}
}

int	print_o(t_flags *flags, unsigned int o)
{
	int	c;

	flags->o = u_nbrlen_base(o, 8, flags);
	if (!flags->zero || flags->point || !flags->o)
		c = ' ';
	else
		c = '0';
	if (!flags->min && (!flags->zero || flags->point))
		repeat_putc_for_o(flags, c);
	if (o > 0 && flags->sharp)
		ft_putchar('0');
	if (!flags->min && flags->zero && !flags->point)
		repeat_putc_for_o(flags, c);
	if (flags->point > flags->o)
		repeat_putchar('0', flags->point - flags->o);
	if (flags->o)
		ft_putnbr_base_u(o, "01234567", 8);
	if (flags->min)
		repeat_putc_for_o(flags, ' ');
	if (flags->len > flags->o && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->o)
		return (flags->point);
	return (flags->o);
}
