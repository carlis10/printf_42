/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unnum_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:54:14 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/29 19:50:49 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_unnum_dot(unsigned long n, t_format size, char *flags)
{
	int	count;

	count = unnum_size(n, size, flags);
	if (count < size.max)
		count += size.max - count;
	count += ft_set_simbol_un(flags, 0);
	if (count < size.min && !ft_strchr(flags, '-'))
		count += ft_add_num_diff(size.min - count, ' ');
	ft_set_simbol_un(flags, 1);
	if (unnum_size(n, size, flags) < size.max)
		ft_add_num_diff(size.max - unnum_size(n, size, flags), '0');
	return (count - unnum_size(n, size, flags));
}

int	ft_set_simbol_un(char *flags, int print)
{
	int	count;

	count = 0;
	if ((ft_strchr(flags, '+')))
	{
		if (print == 1)
			ft_putchar_fd('+', 1);
		count++;
	}
	else if (ft_strchr(flags, ' '))
	{
		if (print == 1)
			ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int	unnum_size(unsigned long n, t_format size, char *flags)
{
	int	i;

	i = 0;
	if (ft_strchr(flags, '.') && n == 0 && size.max == 0)
		return (0);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_hexa_cont(char *num, char *flags, t_format size, char *base)
{
	int	count;
	count = 0;
	if (ft_strchr(flags, '.'))
		count += ft_dot_hexa(num, flags, size, base);
	else if (ft_strchr(flags, '0') && !ft_strchr(flags, '-') && \
			(ft_strlen(num) + ft_put_simbol_hex(flags, base, 0)) \
			<= size.last)
	{
		count += ft_add_num_diff(size.last \
			- (ft_strlen(num) + ft_put_simbol_hex(flags, base, 1)), '0');
		count += ft_put_simbol_hex(flags, base, 0);
	}
	else if ((ft_strlen(num) + ft_put_simbol_hex(flags, base, 0)) \
			<= size.last \
			&& !ft_strchr(flags, '-'))
	{
		count += ft_add_num_diff(size.last \
			- (ft_strlen(num) + ft_put_simbol_hex(flags, base, 0)), ' ');
	}
	if (!ft_strchr(flags, '.') && (!ft_strchr(flags, '0') || \
		(ft_strlen(num) + ft_put_simbol_hex(flags, base, 0)) > size.last))
		count += ft_put_simbol_hex(flags, base, 1);
	return (count);
}

int ft_dot_hexa(char *num, char *flags, t_format size, char *base)
{
	int	count;

	count = ft_strlen(num);
	if (count < size.max)
		count += size.max - count;
	count += ft_put_simbol_hex(flags, base, 0);
	if (count < size.min && !ft_strchr(flags, '-'))
		count += ft_add_num_diff(size.min - count, ' ');
	ft_put_simbol_hex(flags, base, 1);
	if (ft_strlen(num) < size.max)
		ft_add_num_diff(size.max - ft_strlen(num), '0');
	return (count - ft_strlen(num));
}
