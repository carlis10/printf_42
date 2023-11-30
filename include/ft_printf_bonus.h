/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:00:39 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/30 14:37:31 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"
# ifndef LOW_HEX
#  define LOW_HEX "0123456789abcdef"
# endif
# ifndef UPP_HEX
#  define UPP_HEX "0123456789ABCDEF"
# endif

typedef struct s_format
{
	int		min;
	int		max;
	int		last;
}					t_format;

int			ft_printf(char const *str, ...);
int			read_arg(char chr, va_list ap, t_format size, char *flags);
int			print_chr(char chr, char *flags, t_format size);
int			print_str(char *str, char *flags, t_format size);
int			print_num(int n, char *flags, t_format size);
int			print_hexa(unsigned int n, char *base, char *flags, t_format size);
int			print_void(va_list ap, char *flags, t_format size);
int			print_unint(unsigned int n, char *flags, t_format size);
int			ft_printf_cont(char const *str, va_list ap, size_t count, int i);
char		*ft_str_add_char(char *str, char chr);
int			ft_countnbr_base(unsigned long n, char *base, size_t count);
int			ft_add_size(char *flags, int diff, int isNum);
int			check_flag(char const *str, va_list ap, int *i);
int			ft_putnbr_fd_pr(long int nl, int fd, size_t count);
char		*ft_putnbr_base(unsigned long n, char *base, char *num);
int			ft_putnbr_fd_pr_unint(unsigned int nl, int fd, size_t count);
int			ft_putstr_fd_pr(char *s, int fd, int max, int count);
t_format	get_size(char const *str, int *i, t_format s, char *flags);
int			print_num_cont(char *flags, int n, int count, t_format size);
int			num_size(int n, t_format size, char *flags);
int			ft_num_dot(int n, t_format size, char *flags);
int			ft_add_num_diff(int diff, char c);
int			ft_set_simbol(int n, char *flags, int print);
t_format	init_size(int val);
int			un_cont(char *flags, unsigned long n, int count, t_format size);
int			ft_unnum_dot(unsigned long n, t_format size, char *flags);
int			ft_set_simbol_un(char *flags, int print);
int			unnum_size(unsigned long n, t_format size, char *flags);
int			ft_put_simbol_hex(char *flags, char *base, int print, char *num);
int			print_hexa_cont(char *num, char *flags, t_format size, char *base);
int			ft_dot_hexa(char *num, char *flags, t_format size, char *base);

#endif