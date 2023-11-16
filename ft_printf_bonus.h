/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:00:39 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/16 13:04:40 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		read_arg(char chr, va_list ap, size_t count, char *flags);
int		print_chr(char chr);
int		print_str(char *str);
int		print_num(int n, char *flags);
int		print_hexa(unsigned int n, char *base, char *flags);
int		print_void(va_list ap);
int		ft_putnbr_fd_pr(int n, int fd, size_t count);
int		ft_putnbr_base(unsigned long nbr, char *base, size_t count);
int		ft_putnbr_fd_pr_unint(unsigned int nl, int fd, size_t count);
int		ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_printf_cont(char const *str, va_list ap, size_t count, int i);

#endif