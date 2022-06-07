/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:59:33 by hrolle            #+#    #+#             */
/*   Updated: 2022/05/23 17:14:33 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct S_t_flags
{
	unsigned int	c;
	unsigned int	s;
	unsigned int	d;
	unsigned int	u;
	unsigned int	x;
	unsigned int	p;
	unsigned int	o;
	unsigned int	upx;
	unsigned int	pourcent;
	unsigned int	min;
	unsigned int	zero;
	unsigned int	plus;
	unsigned int	point;
	unsigned int	zpoint;
	unsigned int	sharp;
	unsigned int	sp;
	unsigned int	len;
}					t_flags;

void	flags_set(t_flags *flags);
void	value_check(const char *str, t_flags *flags, int *i);
int		flags_check(const char *str, va_list args, int *i);
char	*ft_strchr(const char *s, int c);
void	ft_strcpy(char *dst, const char *src);

size_t	ft_strlen(const char *s);
int		nbrlen(long int nbr, unsigned int base, t_flags *flags);
int		cmpt_nbr_c(unsigned int nbr, unsigned int base, unsigned int i);
int		u_nbrlen_base(unsigned long nbr, unsigned long base, t_flags *flags);
int		flag_s_len(char *s, t_flags *flags);
int		len_atoi(const char *str, int *i);

void	ft_putstr(char *s);
void	ft_putstr_l(char *s, int len);
void	rec_putnbr(unsigned int n);
void	ft_putnbr(int n);
void	ft_putnbr_base_u(unsigned long n, char *str, unsigned long base);
void	ft_putchar(char c);
void	repeat_putchar(char c, int len);
void	repeat_putc_for_u(t_flags *flags, int c);
void	repeat_putc_for_o(t_flags *flags, int c);
void	repeat_putc_for_x(t_flags *flags, int c);
void	repeat_putc_for_upx(t_flags *flags, int c);
void	repeat_putc_for_d(t_flags *flags, int c);
void	put_sign(t_flags *flags, int d);

int		print_c(t_flags *flags, int c);
int		print_s(t_flags *flags, char *s);
int		print_d(t_flags *flags, int d);
int		print_u(t_flags *flags, unsigned int u);
int		print_x(t_flags *flags, unsigned long int x);
int		print_upx(t_flags *flags, unsigned long int upx);
int		print_o(t_flags *flags, unsigned int o);
int		print_len(t_flags *flags, int c);

int		text_mod(const char *str, int *i);
void	color(const char *str, int *i);
void	backround(const char *str, int *i);
void	flags_text(const char *str, int *i);
void	bright(const char *str, int *i);
void	bt_backround(const char *str, int *i);

int		ft_printf(const char *str, ...);

#endif
