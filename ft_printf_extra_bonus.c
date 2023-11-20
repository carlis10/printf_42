/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:58:20 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/20 18:29:53 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr_base(unsigned long n, char *base, size_t count)
{
	unsigned int	size;

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

int	ft_countnbr_base(unsigned long n, char *base, size_t count)
{
	unsigned int	size;

	size = ft_strlen(base);
	if (n < size)
		count++;
	else if (n >= size)
	{
		count = ft_countnbr_base(n / size, base, count);
		count = ft_countnbr_base(n % size, base, count);
	}
	return (count);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*m;
	size_t			i;
	unsigned char	*l;

	m = (void *)malloc(count * size);
	if (!m)
		return (NULL);
	l = m;
	i = 0;
	while (i < (count * size))
	{
		l[i] = 0;
		i++;
	}
	return (m);
}

char	*ft_str_add_char(char *str, char chr)
{
	char	*res;
	int		i;

	res = ft_calloc(ft_strlen(str) + 1, sizeof(chr));
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = chr;
	return (res);
}

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
