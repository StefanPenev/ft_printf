#include "ft_printf.h"

int print_nbr(int n)
{
    int len;
    char *num;

    num = ft_itoa(n);
    len = print_str(num);
    free(num);
    return (len);
}