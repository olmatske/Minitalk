

#include "minitalk.h"

char	*msg;

void	signal_handler(int signal)
{
	static char	c;
	static int	bit;

	if (signal == SIGUSR2)
	{
		c |= (0x80 >> bit);
		// printf("1\n");
	}
	else if (signal == SIGUSR1)
	{
		c &= ~(0x80 >> bit);
		// printf("0\n");
	}
	bit++;
	if (bit == 8)
	{
		msg_append(c);
		if (c == '\0')
		{
			printf("%s\n", msg);
			exit(0);
		}
		c = 0;
		bit = 0;
	}
}

// main function writes singals into a char and appends into a msg, has 8 iterations
void	msg_append(char c)
{
	int	len;

	len = ft_strlen(msg);
	msg[len] = c;
	msg[len + 1] = '\0';
}

int	main(void)
{
	printf("Server PID: %d\n", getpid());
	msg = ft_calloc(1024, sizeof(char));
		if (!msg)
			return (1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
