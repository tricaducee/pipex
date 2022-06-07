/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:47:58 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/26 20:48:05 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

int	print_len(t_flags *flags, int c)
{
	if (!flags->len)
		return (write(1, &c, 1));
	if (flags->min)
		ft_putchar(c);
	if (flags->zero && !flags->min)
		repeat_putchar('0', flags->len - 1);
	else
		repeat_putchar(' ', flags->len - 1);
	if (!flags->min)
		ft_putchar(c);
	return (flags->len);
}
