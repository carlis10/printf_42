/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:00:39 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/30 14:34:11 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

int		ft_printf(char const *str, ...);
int		read_arg(char chr, va_list ap, size_t count);
int		print_chr(char chr);
int		print_str(char *str);
int		print_void(va_list ap);
int		ft_putnbr_fd_pr(int n, int fd, size_t count);
int		ft_putnbr_base(unsigned long nbr, char *base, size_t count);
int		ft_putnbr_fd_pr_unint(unsigned int nl, int fd, size_t count);

#endif