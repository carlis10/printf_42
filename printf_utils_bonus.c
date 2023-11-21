/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:26 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/21 11:28:36 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_chr(char chr, char *flags, int size)
{
	int	count;

	count = 1;
	if (count < size && !(ft_strchr(flags, '-')))
		count += ft_add_size(flags, (size - count));
	ft_putchar_fd(chr, 1);
	return (count);
}

int	print_str(char *str, char *flags, int size)
{
	int	count;

	if (!str)
	{
		count = 6;
		if (count < size && !(ft_strchr(flags, '-')))
			count += ft_add_size(flags, (size - count));
		ft_putstr_fd("(null)", 1);
		return (count);
	}
	count = ft_strlen(str);
	if (count < size && !(ft_strchr(flags, '-')))
		count += ft_add_size(flags, (size - count));
	ft_putstr_fd(str, 1);
	return (count);
}

int	print_num(int n, char *flags, int size)
{
	int	count;

	count = 0;
	if (ft_strchr(flags, ' ') && !(ft_strchr(flags, '+')) && \
		n > 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	if (ft_strchr(flags, '+') && (n > 0))
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	count = ft_count_nbr(n, count);
	if (count < size && !(ft_strchr(flags, '-')))
		count += ft_add_size(flags, (size - count));
	ft_putnbr_fd_pr(n, 1, count);
	return (count);
}

int	print_hexa(unsigned int n, char *base, char *flags, int size)
{
	int	count;

	count = 0;
	if (ft_strchr(flags, '#'))
	{
		ft_putchar_fd('0', 1);
		if (ft_strchr(base, 'f'))
			ft_putchar_fd('x', 1);
		else
			ft_putchar_fd('X', 1);
		count += 2;
	}
	count = ft_countnbr_base(n, base, count);
	if (count < size && !(ft_strchr(flags, '-')))
		count += ft_add_size(flags, (size - count));
	ft_putnbr_base(n, base, count);
	return (count);
}

int	print_void(va_list ap, char *flags, int size)
{
	int	count;

	count = 2;
	ft_putstr_fd("0x", 1);
	count = ft_countnbr_base(va_arg(ap, unsigned long), LOW_HEX, count);
	if (count < size && !(ft_strchr(flags, '-')))
		count += ft_add_size(flags, (size - count));
	ft_putnbr_base(va_arg(ap, unsigned long), LOW_HEX, count);
	return (count);
}
