/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:44 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:18:51 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	repeat_putc_for_u(t_flags *flags, int c)
{
	if (flags->len > flags->u
		|| (flags->point > flags->u && flags->len > flags->point))
	{
		if (flags->point > flags->u)
			repeat_putchar(c, flags->len - flags->point);
		else
			repeat_putchar(c, flags->len - flags->u);
	}
}

int	print_u(t_flags *flags, unsigned int u)
{
	int	c;

	flags->u = u_nbrlen_base(u, 10, flags);
	if (!flags->zero || flags->point || !flags->u)
		c = ' ';
	else
		c = '0';
	if (!flags->min)
		repeat_putc_for_u(flags, c);
	if (flags->point > flags->u)
		repeat_putchar('0', flags->point - flags->u);
	if (flags->u)
		ft_putnbr_base_u(u, "0123456789", 10);
	if (flags->min)
		repeat_putc_for_u(flags, ' ');
	if (flags->len > flags->u && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->u)
		return (flags->point);
	return (flags->u);
}
