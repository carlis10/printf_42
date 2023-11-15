/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:27:37 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/06 13:15:46 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_pr(int n, int fd, size_t count)
{
	long int	nl;
	char		c;

	nl = n;
	if (nl < 0)
	{
		nl = -nl;
		ft_putchar_fd('-', fd);
		count++;
	}
	if (nl > 9)
	{
		ft_putnbr_fd_pr(nl / 10, fd, count);
		ft_putnbr_fd_pr(nl % 10, fd, count);
	}
	else
	{
		c = nl + '0';
		ft_putchar_fd(c, fd);
		count++;
	}
	return (count);
}

int	ft_putnbr_fd_pr_unint(unsigned int nl, int fd, size_t count)
{
	char	c;

	if (nl > 9)
	{
		ft_putnbr_fd_pr(nl / 10, fd, count);
		ft_putnbr_fd_pr(nl % 10, fd, count);
	}
	else
	{
		c = nl + '0';
		ft_putchar_fd(c, fd);
		count++;
	}
	return (count);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
