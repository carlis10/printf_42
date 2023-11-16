/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:04:35 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/16 14:33:07 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	read_arg(char chr, va_list ap, size_t count, char *flags)
{
	if (chr == 'c')
		count = print_chr((char) va_arg(ap, int));
	else if (chr == 's')
		count = print_str(va_arg(ap, char *));
	else if (chr == 'p')
		count = print_void(ap);
	else if (chr == 'd' || chr == 'i')
		count = print_num(va_arg(ap, int), flags);
	else if (chr == 'u')
		count = ft_putnbr_fd_pr_unint(va_arg(ap, unsigned int), 1, 0);
	else if (chr == 'x')
		count = print_hexa(va_arg(ap, unsigned int), "0123456789abcdef", flags);
	else if (chr == 'X')
		count = print_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF", flags);
	else if (chr == '%')
	{
		ft_putchar_fd(chr, 1);
		count++;
	}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	size_t	count;
	int		i;

	if (!str)
		return (0);
	i = 0;
	va_start(ap, str);
	count = 0;
	count = ft_printf_cont(str, ap, count, i);
	va_end(ap);
	return (count);
}

int	ft_printf_cont(char const *str, va_list ap, size_t count, int i)
{
	char	*flags;

	flags = ft_calloc(1, 1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (str[i + 1] == '#' || str[i + 1] == '+' || str[i + 1] == ' ')
			{
				flags = ft_strjoin(flags, &str[i + 1]);
				i++;
				//ft_printf("%s\n", flags);
			}
			count += read_arg(str[i + 1], ap, count, flags);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	free (flags);
	return (count);
}

/* int main()
{
	ft_printf("propia: %i\n", ft_printf("%#x", 123));
	ft_printf("original: %i\n", printf("%#x", 123));
	return (0);
} */
