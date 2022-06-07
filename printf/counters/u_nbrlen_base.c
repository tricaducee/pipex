/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_nbrlen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:58 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:20:04 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

int	u_nbrlen_base(unsigned long nbr, unsigned long base, t_flags *flags)
{
	unsigned int	i;

	i = 0;
	if (flags->zpoint && !nbr)
		return (0);
	if ((flags->sharp && nbr > 0 && base > 10) || flags->p)
	{
		if (flags->point)
			flags->point += 2;
		i += 2;
	}
	else if (flags->sharp && nbr > 0 && base < 10)
		i++;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i + 1);
}
