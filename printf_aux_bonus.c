/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_aux_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:27:37 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/29 16:21:25 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_format	init_size(int val)
{
	t_format	size;

	size.min = val;
	size.max = val;
	size.last = val;
	return (size);
}

int	un_cont(char *flags, unsigned long n, int count, t_format size)
{
	if (ft_strchr(flags, '.'))
		count += ft_unnum_dot(n, size, flags);
	else if (ft_strchr(flags, '0') && !ft_strchr(flags, '-') && \
			((unnum_size(n, size, flags) + ft_set_simbol_un(flags, 0)) \
			<= size.last))
	{
		count += ft_add_num_diff(size.last - \
		(unnum_size(n, size, flags) + ft_set_simbol_un(flags, 1)), '0');
		count += ft_set_simbol_un(flags, 0);
	}
	else if ((unnum_size(n, size, flags) + ft_set_simbol_un(flags, 0)) \
			<= size.last \
			&& !ft_strchr(flags, '-'))
	{
		count += ft_add_num_diff(size.last - \
			(unnum_size(n, size, flags) + ft_set_simbol_un(flags, 0)), ' ');
	}
	if (!ft_strchr(flags, '.') && (!ft_strchr(flags, '0') || \
	(unnum_size(n, size, flags) + ft_set_simbol_un(flags, 0)) > size.last))
		count += ft_set_simbol_un(flags, 1);
	return (count);
}

int	print_unint(unsigned int n, char *flags, t_format size)
{
	int	count;

	count = 0;
	count = un_cont(flags, n, count, size);
	if (ft_strchr(flags, '.') && n == 0 && size.max == 0)
		return (count);
	count = ft_putnbr_fd_pr_unint(n, 1, count);
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
	return (0);
}

int	print_num_cont(char *flags, int n, int count, t_format size)
{
	if (ft_strchr(flags, '.'))
		count += ft_num_dot(n, size, flags);
	else if (ft_strchr(flags, '0') && !ft_strchr(flags, '-') && \
			((num_size(n, size, flags) + ft_set_simbol(n, flags, 0)) \
			<= size.last))
	{
		count += ft_add_num_diff(size.last \
			- (num_size(n, size, flags) + ft_set_simbol(n, flags, 1)), '0');
		count += ft_set_simbol(n, flags, 0);
	}
	else if ((num_size(n, size, flags) + ft_set_simbol(n, flags, 0)) \
			<= size.last \
			&& !ft_strchr(flags, '-'))
	{
		count += ft_add_num_diff(size.last \
			- (num_size(n, size, flags) + ft_set_simbol(n, flags, 0)), ' ');
	}
	if (!ft_strchr(flags, '.') && (!ft_strchr(flags, '0') || \
		(num_size(n, size, flags) + ft_set_simbol(n, flags, 0)) > size.last))
		count += ft_set_simbol(n, flags, 1);
	return (count);
}
