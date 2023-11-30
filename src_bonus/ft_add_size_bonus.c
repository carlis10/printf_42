/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_size_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:50:23 by Carlos            #+#    #+#             */
/*   Updated: 2023/11/30 14:37:58 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_add_size(char *flags, int diff, int isNum)
{
	int		i;
	char	chr;

	i = 0;
	chr = ' ';
	if ((ft_strchr(flags, '.') || ft_strchr(flags, '0')) \
		&& (!(ft_strchr(flags, '-')) && (isNum == 1)))
		chr = '0';
	while (i < diff)
	{
		ft_putchar_fd(chr, 1);
		i++;
	}
	return (diff);
}

int	ft_putstr_fd_pr(char *s, int fd, int max, int count)
{
	int	i;

	i = 0;
	while (s[i] && (count < max || max == -1))
	{
		ft_putchar_fd(s[i], fd);
		count++;
		i++;
	}
	return (count);
}

int	ft_putnbr_fd_pr_unint(unsigned int nl, int fd, size_t count)
{
	char	c;

	if (nl > 9)
	{
		count = ft_putnbr_fd_pr_unint(nl / 10, fd, count);
		count = ft_putnbr_fd_pr_unint(nl % 10, fd, count);
	}
	else
	{
		c = nl + '0';
		ft_putchar_fd(c, fd);
		count++;
	}
	return (count);
}
