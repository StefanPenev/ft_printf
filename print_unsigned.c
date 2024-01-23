#include "ft_printf.h"

static int	count_digits(unsigned int n)
{
	int count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char *utoa(unsigned int n)
{
    char *num;
    int len;

    len = count_digits(n);
    num = (char *)malloc(sizeof(char) * (len + 1));
    if (!num)
        return (0);
    num[len] = '\0';
    while (n != 0)
	{
		num[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
    return (num);
}

int print_unsigned(unsigned int n)
{
    char *num;
    if (n == 0)
        ft_putchar_fd('0', 1);
    else
    {
        num = utoa(n);
        print_str(num);
        free(num);
    }
    return (count_digits(n));
}