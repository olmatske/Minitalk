/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:42:44 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/20 13:06:47 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"
# include "./lib/ft_printf/ft_printf.h"

void	msg_append(char c);
void	signal_handler(int singal);
void	bit_convert(int pid, char *msg);
void	sigint_handler(int signal);

#endif