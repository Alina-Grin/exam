#include <unistd.h>
#include <stdio.h>

int main(int argv, char **argc)
{
    int i;
    int j;

    i = 0;
    if (argv == 2)
    {
        while (argc[1][i] != '\0')
        {
            if (argc[1][i] >= 'a' && argc[1][i] <= 'z') 
            {
                j = 0;
                while (j++ < (argc[1][i]) - 96)
                    write(1, &argc[1][i], 1);
            }
            else if (argc[1][i] >= 'A' && argc[1][i] <= 'Z')
            {
                j = 0;
                while (j++ < (argc[1][i]) - 64)
                    write(1, &argc[1][i], 1);
            }
            else
                write(1, &argc[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}