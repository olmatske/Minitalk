/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:42:00 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/16 18:13:35 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg;

void	signal_handler(int signal)
{
	static char	c;
	static int	bit;

	if (signal == SIGUSR2)
		c |= (0x80 >> bit);
	else if (signal == SIGUSR1)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		if (!g_msg)
			g_msg = ft_calloc(70000, sizeof(char));
		msg_append(c);
		if (c == '\0')
		{
			printf("%s\n", g_msg);
			free(g_msg);
			g_msg = NULL;
		}
		c = 0;
		bit = 0;
	}
}

void	msg_append(char c)
{
	int	len;

	len = ft_strlen(g_msg);
	g_msg[len] = c;
	g_msg[len + 1] = '\0';
}

void	sigint_handler(int signal)
{
	(void)signal;
	if (g_msg)
		free(g_msg);
	exit(0);
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	g_msg = NULL;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGINT, sigint_handler);
	while (1)
		pause();
	return (0);
}
