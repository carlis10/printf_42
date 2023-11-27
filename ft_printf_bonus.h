/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:00:39 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/27 15:30:19 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
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
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t count, size_t size);
int			ft_printf_cont(char const *str, va_list ap, size_t count, int i);
char		*ft_str_add_char(char *str, char chr);
int			ft_count_unint(unsigned int nl, size_t count);
int			ft_count_nbr(int n, size_t count);
int			ft_countnbr_base(unsigned long n, char *base, size_t count);
int			ft_add_size(char *flags, int diff, int isNum);
int			check_flag(char const *str, va_list ap, int *i);
int			ft_putnbr_fd_pr(long int nl, int fd, size_t count);
int			ft_putnbr_base(unsigned long nbr, char *base, size_t count);
int			ft_putnbr_fd_pr_unint(unsigned int nl, int fd, size_t count);
int			ft_strlen(const char *s);
int			ft_putstr_fd(char *s, int fd, int max, int count);
void		ft_putchar_fd(char c, int fd);
t_format	get_size(char const *str, int *i, t_format s, char *flags);
int			print_num_extra(char *flags, int n, int count);

#endif