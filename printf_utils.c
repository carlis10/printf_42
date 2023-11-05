/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:19:26 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/05 18:39:35 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_chr(va_list ap)
{
	char	chr;

	chr = (char) va_arg(ap, char);
	ft_putstr_fd(chr, 0);
	return (1);
}

int	print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_fd(str, 0);
	return (ft_strlen(str));
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
