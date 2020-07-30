#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strdup(const char *s)
{
    char    *dups;
    int     i;

    i = 0;
    while (s[i] != '\0')
        i++;
    dups = (char *)malloc((i + 1)*sizeof(char));
    if (!dups)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        dups[i] = s[i];
        i++;
    }
    dups[i] = '\0';
    return (dups);
}

int main(void)
{
    printf("%s\n", strdup("asdfgh"));
    printf("%s\n", ft_strdup("asdfgh"));
    return (0);
}