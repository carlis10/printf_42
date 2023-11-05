/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:58:20 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/05 18:33:56 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_check_base(char *base, int *size)
{
	int	j;
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (j != i && base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+' || base[i] < ' ' || base[i] > '~')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	*size = i;
	return (1);
}

void	ft_putnbr_base(int nbr, char *base, size_t count)
{
	int			r;
	long int	n;
	int			size;

	r = ft_check_base(base, &size);
	if (r == 1)
	{
		n = nbr;
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			count++;
			n *= -1;
		}
		if (n < size)
		{
			ft_putchar_fd(&base[n], 1);
			count++;
		}
		else if (n >= size)
		{
			ft_putnbr_base(n / size, base, count);
			ft_putnbr_base(n % size, base, count);
		}
	}
}
