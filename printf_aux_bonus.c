/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_aux_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:27:37 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/27 15:34:55 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_count_nbr(int n, size_t count)
{
	long int	nl;

	nl = n;
	if (nl < 0)
		nl = -nl;
	if (nl > 9)
	{
		count = ft_count_nbr(nl / 10, count);
		count = ft_count_nbr(nl % 10, count);
	}
	else
		count++;
	return (count);
}

int	ft_count_unint(unsigned int nl, size_t count)
{
	if (nl > 9)
	{
		count = ft_count_unint(nl / 10, count);
		count = ft_count_unint(nl % 10, count);
	}
	else
		count++;
	return (count);
}

int	print_unint(unsigned int n, char *flags, t_format size)
{
	int	count;

	count = ft_count_unint(n, 0);
	if (count < size.last && !(ft_strchr(flags, '-')))
		count += ft_add_size(flags, (size.last - count), 1);
	ft_putnbr_fd_pr_unint(n, 1, count);
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int		print_num_extra(char *flags, int n, int count)
{
	if (ft_strchr(flags, ' ') && !(ft_strchr(flags, '+')) && \
		n >= 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	if (ft_strchr(flags, '+') && (n >= 0))
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	return (count);
}
