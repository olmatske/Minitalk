/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedputnbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:09:41 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/03 16:13:49 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digitprint(unsigned long n);

int	ft_unsignedputnbr(unsigned int n)
{
	int				count;
	unsigned int	num;
	int				res;

	count = 0;
	num = n;
	res = digitprint(num);
	if (res == -1)
		return (-1);
	return (count + res);
}

static int	digitprint(unsigned long n)
{
	int	res;
	int	num;

	res = 0;
	num = 0;
	if (n > 9)
	{
		num = digitprint(n / 10);
		if (num == -1)
			return (-1);
		res += num;
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (res + 1);
}
