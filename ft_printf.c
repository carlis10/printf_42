/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:04:35 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/05 18:41:00 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_param_type(char fmt, va_list ap, size_t count)
{
	if (fmt == 'c')
		count = print_chr(ap);
	else if (fmt == 's')
		print_str(ap);
	else if (fmt == 'p')
		print_void(ap);
	else if (fmt == 'd' || fmt == 'i')
		ft_putnbr_fd_pr(va_arg(ap, int), 0, count);
	else if (fmt == '%')
	{
		ft_putchar_fd(fmt, 0);
		count++;
	}
	return (count);
}

int	ft_prinft(char const *fmt, ...)
{
	va_list	ap;
	size_t	count;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	count = 0;
	while (fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			check_param_type(*fmt, ap, count);
		}
		else
		{
			ft_putchar_fd(*fmt, 0);
			count++;
		}
		fmt++;
	}
	va_end(ap);
	return (count);
}
