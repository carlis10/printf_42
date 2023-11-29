/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:26 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/29 16:17:58 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_chr(char chr, char *flags, t_format size)
{
	int	count;

	count = 1;
	if (count < size.min && !(ft_strchr(flags, '-')))
		count += ft_add_size(flags, (size.min - count), 0);
	ft_putchar_fd(chr, 1);
	return (count);
}

int	print_str(char *str, char *flags, t_format size)
{
	int	count;

	if (!str)
		str = "(null)";
	if (size.max != -1 && size.max < ft_strlen(str))
		count = ft_strlen(str) - (ft_strlen(str) - size.max);
	else
		count = ft_strlen(str);
	if (count < size.min && !(ft_strchr(flags, '-')))
		count = ft_add_size(flags, (size.min - count), 0);
	else
		count = 0;
	count += ft_putstr_fd(str, 1, size.max, 0);
	return (count);
}

int	print_num(int n, char *flags, t_format size)
{
	int				count;
	unsigned int	nl;

	count = 0;
	count = print_num_cont(flags, n, count, size);
	if (n > 0)
		nl = n;
	else
		nl = -n;
	if (ft_strchr(flags, '.') && nl == 0 && size.max == 0)
		return (count);
	count = ft_putnbr_fd_pr(nl, 1, count);
	return (count);
}

int	print_hexa(unsigned int n, char *base, char *flags, t_format size)
{
	int	count;

	count = 0;
	if (ft_strchr(flags, '#') && n != 0)
	{
		ft_putchar_fd('0', 1);
		if (ft_strchr(base, 'f'))
			ft_putchar_fd('x', 1);
		else
			ft_putchar_fd('X', 1);
		count += 2;
	}
	count = un_cont(flags, n, count, size);
	if (ft_strchr(flags, '.') && n == 0 && size.max == 0)
		return (count);
	count = ft_putnbr_base(n, base, count);
	return (count);
}

int	print_void(va_list ap, char *flags, t_format size)
{
	int				count;
	unsigned long	n;

	n = va_arg(ap, unsigned long);
	count = 2;
	count = ft_countnbr_base(n, LOW_HEX, count);
	if (count < size.last && !(ft_strchr(flags, '-')))
		count = ft_add_size(flags, (size.last - count), 1);
	else
		count = 0;
	count += ft_putstr_fd("0x", 1, -1, 0);
	count = ft_putnbr_base(n, LOW_HEX, count);
	return (count);
}
