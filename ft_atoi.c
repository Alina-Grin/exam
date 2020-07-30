#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str)
{
    int i;
    unsigned long long int n;
    int neg;

    i = 0;
    neg = 1;
    n = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
        i++;
    if (str[i] == '-')
        {
            neg = -1;
            i++;
        }
    if (str[i] == '+')
            i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        n = n * 10;
        n = n + (unsigned long long int)(str[i] - 48);
        i++;
    }
    if (neg == -1 && n > 9223372036854775807)
        return (-1);
    else if (neg == -1 && n > 2147483648)
        return (0);
    return ((int)n * neg);
}

int main(void)
{
    printf("%d\n", ft_atoi(" -9223372036854775808"));
    printf("%d\n", atoi(" -9223372036854775808"));
    return (0);
}