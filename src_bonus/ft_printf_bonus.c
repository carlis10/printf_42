/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cravegli <cravegli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:04:35 by cravegli          #+#    #+#             */
/*   Updated: 2023/12/07 13:56:00 by cravegli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include <stdio.h>

int	read_arg(char chr, va_list ap, t_format size, char *flags)
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
		if (1 < size.min && !(ft_strchr(flags, '-')))
			count += ft_add_size(flags, (size.min - 1), 1);
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
	int			count;
	t_format	size;
	char		*flags;

	flags = (char *)ft_calloc(1, 1);
	count = 0;
	size = init_size(0);
	size = get_size(str, i, size, flags);
	while (str[*i + 1] == '#' || str[*i + 1] == '+' || str[*i + 1] == ' ' || \
			str[*i + 1] == '.' || str[*i + 1] == '0' || str[*i + 1] == '-')
	{
		flags = ft_str_add_char(flags, str[*i + 1]);
		i[0]++;
		if ((str[*i + 1] >= '0' && str[*i + 1] <= '9') || ft_strchr(flags, '.'))
			size = get_size(str, i, size, flags);
	}
	count += read_arg(str[*i + 1], ap, size, flags);
	if (count < size.min && ft_strchr(flags, '-'))
		count += ft_add_size(flags, (size.min - count), 0);
	free(flags);
	return (count);
}

t_format	get_size(char const *str, int *i, t_format s, char *flags)
{
	int	size;

	size = 0;
	if (s.min == 0 && str[*i + 1] == '0')
		return (s);
	while (str[*i + 1] >= '0' && str[*i + 1] <= '9')
	{
		size *= 10;
		size += str[*i + 1] - '0';
		i[0]++;
	}
	if (!(ft_strchr(flags, '.')))
	{
		s.min = size;
		s.max = -1;
	}
	else
		s.max = size;
	s.last = size;
	return (s);
}

/* int	main()
{
	printf("Propia Bytes: %i\n",ft_printf("|%i|", INT_MAX));
	printf("Original Bytes: %i\n",printf("|%i|", 54));
	return (0);
} */
