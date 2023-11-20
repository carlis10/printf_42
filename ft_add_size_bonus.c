/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_size_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:50:23 by Carlos            #+#    #+#             */
/*   Updated: 2023/11/20 15:44:23 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_add_size(char *flags, int diff)
{
	int		i;
	char	chr;

	i = 0;
	chr = ' ';
	if ((ft_strchr(flags, '.') || ft_strchr(flags, '0')) \
		&& !(ft_strchr(flags, '-')))
		chr = '0';
	while (i < diff)
	{
		ft_putchar_fd(chr, 1);
		i++;
	}
	return (diff);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_fd_pr_unint(unsigned int nl, int fd, size_t count)
{
	char	c;

	if (nl > 9)
	{
		count = ft_putnbr_fd_pr(nl / 10, fd, count);
		count = ft_putnbr_fd_pr(nl % 10, fd, count);
	}
	else
	{
		c = nl + '0';
		ft_putchar_fd(c, fd);
		count++;
	}
	return (count);
}
