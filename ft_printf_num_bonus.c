/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:14:07 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/29 15:55:06 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_num_dot(int n, t_format size, char *flags)
{
	int	count;

	count = num_size(n, size, flags);
	if (count < size.max)
		count += size.max - count;
	count += ft_set_simbol(n, flags, 0);
	if (count < size.min && !ft_strchr(flags, '-'))
		count += ft_add_num_diff(size.min - count, ' ');
	ft_set_simbol(n, flags, 1);
	if (num_size(n, size, flags) < size.max)
		ft_add_num_diff(size.max - num_size(n, size, flags), '0');
	return (count - num_size(n, size, flags));
}

int	num_size(int n, t_format size, char *flags)
{
	int	i;

	i = 0;
	if (ft_strchr(flags, '.') && n == 0 && size.max == 0)
		return (0);
	if (n == 0)
		return (1);
	if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	else
	{
		while (n < 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

int	ft_set_simbol(int n, char *flags, int print)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (print == 1)
			ft_putchar_fd('-', 1);
		count++;
	}
	if (n >= 0 && (ft_strchr(flags, '+')))
	{
		if (print == 1)
			ft_putchar_fd('+', 1);
		count++;
	}
	else if (n >= 0 && ft_strchr(flags, ' '))
	{
		if (print == 1)
			ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int	ft_add_num_diff(int diff, char c)
{
	int	count;

	count = 0;
	while (count < diff)
	{
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
}
