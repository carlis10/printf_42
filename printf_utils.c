/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:26 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/03 13:25:14 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_chr(va_list ap, size_t count)
{
	char	chr;

	chr = (char) va_arg(ap, char);
	ft_putstr_fd(chr, 0);
	count++;
}

void	print_str(va_list ap, size_t count)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_fd(str, 0);
	count += ft_strlen(str);
}

void	print_void(va_list ap, size_t count)
{
	void	*arg;

	arg = va_arg(ap, void *);
	
}

void	print_dec(va_list ap, size_t count)
{
	
}

void	print_int(va_list ap, size_t count)
{
	
}
