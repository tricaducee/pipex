/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:13:44 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:13:49 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printf.h"

void	flags_set(t_flags *flags)
{
	flags->c = 0;
	flags->s = 0;
	flags->d = 0;
	flags->u = 0;
	flags->x = 0;
	flags->p = 0;
	flags->o = 0;
	flags->upx = 0;
	flags->pourcent = 0;
	flags->min = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->point = 0;
	flags->zpoint = 0;
	flags->sharp = 0;
	flags->sp = 0;
	flags->len = 0;
}

void	value_check(const char *str, t_flags *flags, int *i)
{
	while (ft_strchr("-0123456789+.# p", str[*i]))
	{
		if (str[*i] == '-')
			flags->min = 1;
		else if (str[*i] == '0')
			flags->zero = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		else if (str[*i] == '#')
			flags->sharp = 1;
		else if (str[*i] == 'p')
			flags->p = 1;
		else if (str[*i] == ' ')
			flags->sp = 1;
		else if (str[*i] >= '1' && str[*i] <= '9' && !flags->point)
			flags->len = len_atoi(str, i);
		else if (str[*i] == '.' && (str[*i + 1] > '9' || str[*i + 1] < '1'))
			flags->zpoint = 1;
		else if (str[*i] == '.')
			flags->point = len_atoi(str, i);
		if (!str[*i] || str[*i] == 'p')
			break ;
		*i += 1;
	}
}

int	flags_check(const char *str, va_list args, int *i)
{
	t_flags	flags;

	flags_set(&flags);
	value_check(str, &flags, i);
	if (str[*i] == '%')
		return (print_c(&flags, '%'));
	else if (str[*i] == 'c')
		return (print_c(&flags, va_arg(args, int)));
	else if (str[*i] == 's')
		return (print_s(&flags, va_arg(args, char *)));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (print_d(&flags, va_arg(args, int)));
	else if (str[*i] == 'u')
		return (print_u(&flags, va_arg(args, unsigned int)));
	else if (str[*i] == 'x')
		return (print_x(&flags, va_arg(args, unsigned int)));
	else if (str[*i] == 'p')
		return (print_x(&flags, va_arg(args, unsigned long int)));
	else if (str[*i] == 'X')
		return (print_upx(&flags, va_arg(args, unsigned int)));
	else if (str[*i] == 'o')
		return (print_o(&flags, va_arg(args, unsigned int)));
	else if (str[*i])
		return (print_len(&flags, str[*i]));
	return (0);
}
