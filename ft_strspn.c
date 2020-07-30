#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t  ft_strspn(const char *s, const char *accept)
{
	int i;
	int j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != accept[j] && accept[j] != '\0')
				j++;
		if (s[i] == accept[j])
			i++;
		else
			return (i);
	}
	return (i);
}

int main (void)
{    

	char str [11]="0123456789";
	char sym [10]="";
	int  i = 0;

	int n = strspn ("this", "");
	int n1 = ft_strspn ("this", "");
	printf ("%d\n", n);
	printf ("%d\n",n1);
	return (0);
}