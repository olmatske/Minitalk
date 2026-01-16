/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:07:48 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/03 16:11:12 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include "Libft/libft.h"

# if defined(__linux__)
#  define NULL_PTR "(nil)"
# elif defined(__APPLE__)
#  define NULL_PTR "0x0"
# endif

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	hexconvert(unsigned int n, char *hex);
int	ptrconvert(void *ptr);
int	ft_unsignedputnbr(unsigned int n);

#endif