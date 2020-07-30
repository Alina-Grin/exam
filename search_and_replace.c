#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char **argc)
{
	int i;

	if (argv == 4)
	{
		if (argc[2][1] || argc[3][1])
		{
			write (1, "\n", 1);
			exit (0);
		}
		i = 0;
		while (argc[1][i] != '\0')
		{
			if (argc[1][i] == argc[2][0])
				write (1, &argc[3][0], 1);
			else
				write (1, &argc[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}