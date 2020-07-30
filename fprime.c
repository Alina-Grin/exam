#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int nb;
    int div;

    if (ac == 2)
    {
        nb = atoi(av[1]);
        if (nb == 1)
            printf("1");
        div = 2;
        while (div <= nb)
        {
            if (nb % div == 0)
            {
                printf("%d", div);
                if (div == nb)
                    break ;
                printf("*");
                nb = nb / div;
                div = 1;
            }
            div++;
        }
    }
    printf("\n");
    return (0);
} 

