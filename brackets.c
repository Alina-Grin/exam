#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i;
    int num_str;
    char    par[512];
    int top;

    if (ac > 1)
    {
        num_str = 1;
        while (num_str < ac)
        {
            i = 0;
            top = -1;
            while (av[num_str][i] != '\0')
            {
                if (av[num_str][i]  == '(' || av[num_str][i] == '{' || av[num_str][i] == '[')
                {
                    top++;
                    par[top] = av[num_str][i];
                }
                if (av[num_str][i] == ')' || av[num_str][i] == '}' || av[num_str][i] == ']')
                {
                    if ((par[top] == '(' && av[num_str][i] == ')') ||(par[top] == '[' && av[num_str][i] == ']')
                        ||(par[top] == '{' && av[num_str][i] == '}') )
                    {
                        par[top] = 0;
                        top--;
                    }
                    else
                        top++;
                }
                i++;
            }
            if (top == -1 || par[0] == 0)
                write (1, "OK\n",3);
            else
                write (1, "ERROR\n", 6);
            num_str++;
        }
    }
    else
        write (1, "\n", 1);
    return (0);
}