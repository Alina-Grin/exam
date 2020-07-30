#include <stdlib.h>
#include <unistd.h>

int go_to(char *str, int i)
{
    int direction;
    int count;

    if (str[i] == '[')
        direction = 1;
    else if (str[i] == ']')
        direction = -1;
    count = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '[')
            count++;
        else if (str[i] == ']')
            count--;
        if ((str[i] == '[' || str[i] == ']') && count == 0)
            return (i);
        i += direction;
    }
    return (0);
}

void    brainfuck(char *str)
{
    int     i;
    int     j;
    char    *ptr;

    ptr = (char *)malloc(sizeof(char)*2048);
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '>')
            j++;
        else if (str[i] == '<')
            j--;
        else if (str[i] == '+')
            ptr[j]++;
        else if (str[i] == '-')
            ptr[j]--;
        else if (str[i] == '.')
            write(1, &ptr[j], 1);
        else if ((str[i] == '[' && !(ptr[j])) || (str[i] == ']' && ptr[j]))
            i = go_to(str, i);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
        brainfuck(av[1]);
    else
        write(1, "\n", 1);
    return (0);
}