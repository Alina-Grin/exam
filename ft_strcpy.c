#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	main(void)
{
	char src1[7] = "asdfgh";
	char dst1[7] = "";

	ft_strcpy(dst1, src1);
	printf("%s\n", src1);
	printf("%s\n", dst1);
	return (0);
} 
