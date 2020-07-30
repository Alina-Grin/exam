#include <unistd.h>

int	main(int argv, char **argc)
{
	int	i;

	if (argv > 1)
	{
		i = 0;
		while (argc[argv - 1][i] != '\0')
		{
			write (1, &argc[argv -1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);

}
