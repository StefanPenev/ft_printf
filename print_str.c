#include "ft_printf.h"

int print_str(char *str)
{
    if (str == NULL)
    {
        ft_putstr_fd("(null)", 1);
        return (6);
    }
    else
    {
        ft_putstr_fd(str, 1);
        return (ft_strlen(str));
    }
}