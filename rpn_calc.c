#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		isnum(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	return (0);
}

int operate(int a, int b, char op, int *stack)
{
    if (op == '+')
        *stack = a + b;
    if (op == '-')
        *stack = a - b;
    if (op == '*')
        *stack = a * b;
    if (op == '/')
    {
        if (b != 0)
            *stack = a / b;
        else
            return (1);
    }
    if (op == '%')
    {
        if (b != 0)
            *stack = a % b;
        else
            return (1);
    }
    return (0);
}

int rpn_calc(char *str, int *stack)
{
	int i;
	int top;

	i = 0;
	top = -1;
    while (str[i] != '\0')
    {
        if (isnum(&str[i]))
        {
            top++;
            stack[top] = atoi(&str[i]);
            while (str[i] != ' ' && str[i + 1] != '\0')
                i++;
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
        {
            if (top > 0)
            {
                if (operate (stack[top - 1], stack[top], str[i], &stack[top - 1]) == 1)
                    printf("Error\n");
                top--;
            }
            else
                printf("Error\n");
        }
        i++;
    }
    if (top == 0)
        printf("%d\n", stack[top]);
    else
        printf("Error\n");
    return(0);
}

int main(int ac, char **av)
{
    int stack[512];
    if (ac == 2)
        rpn_calc(av[1], stack);
    else
        printf("Error\n");
    return (0);    
}