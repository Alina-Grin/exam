#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_count_word(char *s)
{
    int	count;
	int	i;

	i = 0;
	count = 0;
	// while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i] != '\0')
	// 	i++;
	while (s[i] != '\0')
	{
		if (s[i] != '\t' && s[i] != '\n' && s[i] != ' ' && (s[i + 1] == '\t' || s[i + 1] == '\n' || s[i + 1] == ' ' || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	ft_len_word(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == ' ') && str[i] != '\0')
		i++;
	while (str[i] != '\t' && str[i] != '\n' && str[i] != ' ' && str[i] !='\0')
	{
		i++;
		len++;
	}
	return(len);
}

char    **ft_split(char *str)
{
    char    **arr;
    int     i;
    int     count_word;
    int     len_word;
	char	*tmp;
	int		j;

	count_word = ft_count_word(str);
    arr = (char **)malloc(sizeof(char *)*(count_word + 1));
    if (arr == NULL)
        return (NULL);
	i = 0;
	tmp = str;
	while (i < count_word)
	{
		j = 0;
		len_word = ft_len_word(tmp);
		if (!(arr[i] = (char *)malloc(sizeof(char) * (len_word + 1))))
			return (NULL);
		while (*tmp == ' ' || *tmp == '\t' || *tmp == '\n')
        	tmp++;
		while (j < len_word)
		{
			arr[i][j] = *tmp;
			j++;
			tmp++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[count_word] = NULL;
	return (arr);
}

int main(int ac, char **av)
{
	int	i;
	char	**array;
	
	array = ft_split(av[1]);
	i = 0;
	while (i < ft_count_word(av[1]))
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}