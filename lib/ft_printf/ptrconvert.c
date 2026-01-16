/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:35:19 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/03 15:25:45 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	long_hexconvert(unsigned long n, char *hex);

int	ptrconvert(void *ptr)
{
	unsigned long	res;
	int				count;

	res = (unsigned long)ptr;
	count = 0;
	if (res == 0)
	{
		if (ft_putstr(NULL_PTR) == -1)
			return (-1);
		return (ft_strlen(NULL_PTR));
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	count += 2;
	count += long_hexconvert(res, "0123456789abcdef");
	return (count);
}

static int	long_hexconvert(unsigned long n, char *hex)
{
	char	res;
	int		num;

	num = 0;
	if (n >= 16)
		num += long_hexconvert(n / 16, hex);
	if (num == -1)
		return (-1);
	res = hex[n % 16];
	if (write(1, &res, 1) == -1)
		return (-1);
	return (num + 1);
}
