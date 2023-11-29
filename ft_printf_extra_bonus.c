/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:58:20 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/29 19:54:46 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_putnbr_base(unsigned long n, char *base, char *num)
{
	unsigned int	size;

	size = ft_strlen(base);
	if (n < size)
		num = ft_str_add_char(num, base[n]);
	else if (n >= size)
	{
		num = ft_putnbr_base(n / size, base, num);
		num = ft_putnbr_base(n % size, base, num);
	}
	return (num);
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

	res = (char *)ft_calloc(ft_strlen(str) + 2, sizeof(chr));
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = chr;
	return (res);
}

int	ft_putnbr_fd_pr(long int nl, int fd, size_t count)
{
	char		c;

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
