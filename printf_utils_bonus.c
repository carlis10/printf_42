/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:26 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/27 15:49:43 by Carlos           ###   ########.fr       */
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
	{
		count = 6;
		if (count < size.min && !(ft_strchr(flags, '-')))
			count += ft_add_size(flags, (size.min - count), 0);
		ft_putstr_fd("(null)", 1, size.max, count);
		return (count);
	}
	count = ft_strlen(str);
	if (count < size.min && !(ft_strchr(flags, '-')))
		count = ft_add_size(flags, (size.min - count), 0);
	else 
		count = 0;
	count = ft_putstr_fd(str, 1, size.max, count);
	return (count);
}

int	print_num(int n, char *flags, t_format size)
{
	int			count;
	long int	nl;

	count = 0;
	if ((ft_strchr(flags, ' ') || ft_strchr(flags, ' ')) && n >= 0)
		count ++;
	count = ft_count_nbr(n, count);
	if (count < size.last && !(ft_strchr(flags, '-')))
		count = ft_add_size(flags, (size.last - count), 1);
	else 
		count = 0;
	count = print_num_extra(flags, n, count);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		nl = -n;
	}
	else
		nl = n;
	count = ft_putnbr_fd_pr(nl, 1, count);
	return (count);
}

int	print_hexa(unsigned int n, char *base, char *flags, t_format size)
{
	int	count;

	count = 0;
	
	count = ft_countnbr_base(n, base, count);
	if (ft_strchr(flags, '#'))
		count += 2;
	if (count < size.last && !(ft_strchr(flags, '-')))
		count = ft_add_size(flags, (size.last - count), 1);
	else 
		count = 0;
	if (ft_strchr(flags, '#') && n != 0)
	{
		ft_putchar_fd('0', 1);
		if (ft_strchr(base, 'f'))
		{
			ft_putchar_fd('x', 1);
			count++;
		}
		else
		{
			ft_putchar_fd('X', 1);
			count++;
		}
		count++;
	}
	count = ft_putnbr_base(n, base, count);
	return (count);
}

int	print_void(va_list ap, char *flags, t_format size)
{
	int	count;

	count = ft_putstr_fd("0x", 1, 0, 0);
	count = ft_countnbr_base(va_arg(ap, unsigned long), LOW_HEX, count);
	if (count < size.last && !(ft_strchr(flags, '-')))
		count = ft_add_size(flags, (size.last - count), 1);
	else 
		count = 0;
	count = ft_putnbr_base(va_arg(ap, unsigned long), LOW_HEX, count + 2);
	return (count);
}
