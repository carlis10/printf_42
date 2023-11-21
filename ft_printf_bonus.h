/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:00:39 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/21 14:09:14 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef LOW_HEX
#  define LOW_HEX "0123456789abcdef"
# endif
# ifndef UPP_HEX
#  define UPP_HEX "0123456789ABCDEF"
# endif

int		ft_printf(char const *str, ...);
int		read_arg(char chr, va_list ap, int size, char *flags);
int		print_chr(char chr, char *flags, int size);
int		print_str(char *str, char *flags, int size);
int		print_num(int n, char *flags, int size);
int		print_hexa(unsigned int n, char *base, char *flags, int size);
int		print_void(va_list ap, char *flags, int size);
int		print_unint(unsigned int n, char *flags, int size);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
int		ft_printf_cont(char const *str, va_list ap, size_t count, int i);
char	*ft_str_add_char(char *str, char chr);
int		ft_count_unint(unsigned int nl, size_t count);
int		ft_count_nbr(int n, size_t count);
int		ft_countnbr_base(unsigned long n, char *base, size_t count);
int		ft_add_size(char *flags, int diff);
int		check_flag(char const *str, va_list ap, int *i);
int		ft_putnbr_fd_pr(int n, int fd, size_t count);
int		ft_putnbr_base(unsigned long nbr, char *base, size_t count);
int		ft_putnbr_fd_pr_unint(unsigned int nl, int fd, size_t count);
int		ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		get_size(char const *str, int *i, int s);

#endif