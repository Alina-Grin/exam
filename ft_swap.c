#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

int		main(void)
{
	int		i;
	int		j;
	int		*pi;
	int		*pj;

	i = 123;
	j = 456;
	pi = &i;
	pj = &j;
	printf("%d\t%d\n", *pi, *pj);
	ft_swap(pi, pj);
	printf("%d\t%d\n", *pi, *pj);
	return (0);
}