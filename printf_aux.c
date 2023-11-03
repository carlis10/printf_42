/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:27:37 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/03 13:33:44 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd_pr(int n, int fd, size_t count)
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
}
