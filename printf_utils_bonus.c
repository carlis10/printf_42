/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:26 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/16 13:59:50 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_chr(char chr)
{
	ft_putchar_fd(chr, 1);
	return (1);
}

int	print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_num(int n, char *flags)
{
	int	count;

	count = 0;
	if (ft_strrchr(flags, ' ') && !(ft_strrchr(flags, '+')))
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	if (ft_strrchr(flags, '+') && (n > 0))
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	count = 0;
	return (ft_putnbr_fd_pr(n, 1, count));
}

int	print_hexa(unsigned int n, char *base, char *flags)
{
	size_t	count;

	count = 0;
	if (ft_strrchr(flags, '#'))
	{
		ft_putchar_fd('0', 1);
		if (ft_strrchr(base, 'f'))
			ft_putchar_fd('x', 1);
		else
			ft_putchar_fd('X', 1);
		count += 2;
	}
	return (ft_putnbr_base(n, base, count));
}

int	print_void(va_list ap)
{
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_base(va_arg(ap, unsigned long), "0123456789abcdef", 2));
}
