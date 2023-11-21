/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:58:20 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/21 22:27:29 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base, size_t count)
{
	unsigned long	size;

	size = ft_strlen(base);
	if (n < size)
	{
		ft_putchar_fd(base[n], 1);
		count++;
	}
	else if (n >= size)
	{
		count = ft_putnbr_base(n / size, base, count);
		count = ft_putnbr_base(n % size, base, count);
	}
	return (count);
}
