/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:53:09 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/03 15:19:35 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexconvert(unsigned int n, char *hex)
{
	char	res;
	int		num;

	num = 0;
	if (n >= 16)
		num += hexconvert(n / 16, hex);
	if (num == -1)
		return (-1);
	res = hex[n % 16];
	if (write(1, &res, 1) == -1)
		return (-1);
	return (num + 1);
}
