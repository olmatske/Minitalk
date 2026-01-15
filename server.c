

#include "minitalk.h"

char	*msg;

void	signal_handler(int signal)
{
	printf("Checkpoint sighandler\n");
	static char	c;
	static int	bit;

	c = 0;
	bit = 0;
	if (signal == SIGUSR2)
	{
		c |= (0x80 >> bit);
		printf("%d\n", signal);
	}
	else if (signal == SIGUSR1)
	{
		c &= ~(0x80 >> bit);
		printf("%d\n", signal);
	}
	bit++;
	printf("meow\n");
	if (bit == 8)
	{
		msg_append(c);
		printf("This is the char:%c\n", c);
		c = 0;
		bit = 0;
	}
}

// main function writes singals into a char and appends into a msg, has 8 iterations
void	msg_append(char c)
{
	ft_strlcat(msg, &c, ft_strlen(msg));
	printf("%s\n", msg);
}

int	main(void)
{
	printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
