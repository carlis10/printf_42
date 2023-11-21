/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:26 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/21 22:20:02 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	print_void(va_list ap)
{
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_base(va_arg(ap, unsigned long), "0123456789abcdef", 2));
}
