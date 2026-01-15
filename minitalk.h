
#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"

void	msg_append(char c);
void	signal_handler(int singal);
void	bit_convert(int pid, char *msg);

# endif