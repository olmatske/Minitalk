/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:51:52 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/03 16:11:27 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

static int	format_type(const char *format, int i, va_list args);
static int	printit(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = printit(format, args);
	va_end(args);
	return (count);
}

static int	printit(const char *format, va_list args)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			flag = format_type(format, ++i, args);
			if (flag == -1)
				return (-1);
			count += flag;
		}
		else
		{
			if (ft_putchar(format[i]) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

static int	format_type(const char *format, int i, va_list args)
{
	if (format[i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format[i] == 'p')
		return (ptrconvert(va_arg(args, void *)));
	else if (format[i] == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format[i] == 'u')
		return (ft_unsignedputnbr(va_arg(args, unsigned int)));
	else if (format[i] == 'x')
		return (hexconvert(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format[i] == 'X')
		return (hexconvert(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format[i] == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%s\n", "Hello there y'all, I'm suffering!");
// 	ft_printf("%s\n", "I'm suffering even more");
// 	return (0);
// }
// printf does the basic function calling
// printit does the writing up until it encounters the %,
// calls formattype, writes arg, goes back and continues until
// null terminator is reached
// hex??? wtf do I do and how do I do it