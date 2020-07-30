#include <unistd.h>

int ft_check_double(char *s, char c, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        if (s[j] == c)
            return (0);
        j++;
    }
    return (1);
}

int main(int ac, char **av)
{
    int i;
    int j;

    if (ac == 3)
    {
        i = 0;
        while (av[1][i])
        {
            if (ft_check_double(av[1], av[1][i], i) == 1)
            {
                j = 0;
                while (av[2][j])
                {
                    if (av[2][j] == av[1][i])
                    {
                        write (1, &av[1][i], 1);
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}