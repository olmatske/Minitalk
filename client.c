/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:41:52 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/16 17:41:56 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	pid = ft_atoi(argv[1]);
	bit_convert(pid, argv[2]);
}

void	bit_convert(int pid, char *msg)
{
	int	i;
	int	k;

	i = 0;
	while (msg[i])
	{
		k = 7;
		while (k >= 0)
		{
			if (msg[i] >> k & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
			k--;
		}
		i++;
	}
	k = 8;
	while (k-- != 0)
	{
		kill(pid, SIGUSR1);
		usleep(500);
	}
}
