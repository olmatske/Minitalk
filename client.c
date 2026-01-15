
#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	pid = ft_atoi(argv[1]);
	bit_convert(pid, argv[2]);
	// kill(pid, sigusr1/sigusr2)
}

void	bit_convert(int pid, char *msg)
{
	int		i;
	int		k;
	char	c;

	i = 0;
	while (msg[i])
	{
		k = 8;
		c = msg[i];
		while (k != 0)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			k--;
		}
		i++;
	}
	k = 8;
	while (k-- != 0) // k-- or --k ??????
		kill(pid, SIGUSR1);
}


// function to convert string into bits
// set destination as pid