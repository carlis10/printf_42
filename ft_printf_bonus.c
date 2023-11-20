/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carlos <Carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:04:35 by cravegli          #+#    #+#             */
/*   Updated: 2023/11/20 19:02:44 by Carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	read_arg(char chr, va_list ap, int size, char *flags)
{
	size_t	count;

	count = 0;
	if (chr == 'c')
		count = print_chr((char) va_arg(ap, int), flags, size);
	else if (chr == 's')
		count = print_str(va_arg(ap, char *), flags, size);
	else if (chr == 'p')
		count = print_void(ap, flags, size);
	else if (chr == 'd' || chr == 'i')
		count = print_num(va_arg(ap, int), flags, size);
	else if (chr == 'u')
		count = print_unint(va_arg(ap, unsigned int), flags, size);
	else if (chr == 'x')
		count = print_hexa(va_arg(ap, unsigned int), LOW_HEX, flags, size);
	else if (chr == 'X')
		count = print_hexa(va_arg(ap, unsigned int), UPP_HEX, flags, size);
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
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += check_flag(str, ap, &i);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	check_flag(char const *str, va_list ap, int *i)
{
	int		count;
	int		size;
	char	*flags;
	char	*tmp;

	flags = (char *)ft_calloc(1, 1);
	count = 0;
	while (str[*i + 1] == '#' || str[*i + 1] == '+' || str[*i + 1] == ' ' || \
			str[*i + 1] == '.' || str[*i + 1] == '0' || str[*i + 1] == '-')
	{
		tmp = flags;
		flags = ft_str_add_char(tmp, str[*i + 1]);
		free(tmp);
		i[0]++;
	}
	size = get_size(str, i);
	count += read_arg(str[*i + 1], ap, size, flags);
	if (count < size && ft_strchr(flags, '-'))
		count += ft_add_size(flags, (size - count));
	free(flags);
	return (count);
}

int	get_size(char const *str, int *i)
{
	int	size;

	size = 0;
	while (str[*i + 1] >= '0' && str[*i + 1] <= '9')
	{
		size *= 10;
		size += str[*i + 1] - '0';
		i[0]++;
	}
	return (size);
}

/* int	main()
{
	ft_printf("Propia Bytes: %i\n",ft_printf("% i.\n", -59));
	ft_printf("Original Bytes: %i\n",printf("% i.\n", -59));
	system("leaks a.out && ./a.out");
	return (0);
} */
