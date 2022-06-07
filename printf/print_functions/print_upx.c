/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:08 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:19:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	repeat_putc_for_upx(t_flags *flags, int c)
{
	if (flags->len > flags->upx
		|| (flags->point > flags->upx && flags->len > flags->point))
	{
		if (flags->point > flags->upx)
			repeat_putchar(c, flags->len - flags->point);
		else
			repeat_putchar(c, flags->len - flags->upx);
	}
}

int	print_upx(t_flags *flags, unsigned long int upx)
{
	int	c;

	flags->upx = u_nbrlen_base(upx, 16, flags);
	if (!flags->zero || flags->point || !flags->upx)
		c = ' ';
	else
		c = '0';
	if (!flags->min && (!flags->zero || flags->point))
		repeat_putc_for_upx(flags, c);
	if (upx > 0 && flags->sharp)
		ft_putstr("0X");
	if (!flags->min && flags->zero && !flags->point)
		repeat_putc_for_upx(flags, c);
	if (flags->point > flags->upx)
		repeat_putchar('0', flags->point - flags->upx);
	if (flags->upx)
		ft_putnbr_base_u(upx, "0123456789ABCDEF", 16);
	if (flags->min)
		repeat_putc_for_upx(flags, ' ');
	if (flags->len > flags->upx && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->upx)
		return (flags->point);
	return (flags->upx);
}
