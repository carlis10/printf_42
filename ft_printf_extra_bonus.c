/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:58:20 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/16 12:42:27 by cravegli         ###   ########.fr       */
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

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	p;
	int				size;

	if (!s)
		return (NULL);
	p = (unsigned char)c;
	size = ft_strlen((char *)s);
	while (size >= 0)
	{
		if (s[size] == p)
			return ((char *)(s + size));
		size--;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	size;
	size_t	src_size;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	s3 = (char *)ft_calloc(size, sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	src_size = 0;
	while (s1[src_size])
		src_size++;
	if (size > 0)
	{
		while (s1[i] && i < (size - 1))
		{
			s3[i] = s1[i];
			i++;
		}
	}
	ft_strlcat(s3, s2, size);
	return (s3);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen((char *)src);
	j = d_len;
	i = 0;
	if (dstsize <= d_len)
		return (s_len + dstsize);
	while (src[i] && (d_len + i) < (dstsize - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	if (dstsize < d_len)
		d_len = dstsize;
	return (d_len + s_len);
}
