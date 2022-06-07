/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:16:51 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:16:58 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

int	cmpt_nbr_c(unsigned int nbr, unsigned int base, unsigned int i)
{
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	nbrlen(long int nbr, unsigned int base, t_flags *flags)
{
	unsigned int	i;
	unsigned int	nbrb;

	i = 0;
	if (flags->zpoint && !nbr)
		return (0);
	if (nbr < 0)
	{
		nbrb = nbr * -1;
		i++;
		if (flags->point)
			flags->point += 1;
	}
	else
	{
		nbrb = (unsigned long )nbr;
		if (flags->sp || flags->plus)
		{
			i++;
			if (flags->point)
				flags->point += 1;
		}
	}
	return (cmpt_nbr_c(nbrb, base, i) + 1);
}
