#include "ft_printf.h"

static int	get_ptr_len(unsigned long long ptr_addres)
{
	int	len;

	len = 0;
	while (ptr_addres != 0)
	{
		len++;
		ptr_addres /= 16;
	}
	return (len);
}

static void	put_ptr(unsigned long long ptr_addres)
{
	if (ptr_addres >= 16)
	{
		put_ptr(ptr_addres / 16);
		put_ptr(ptr_addres % 16);
	}
	else
	{
		if (ptr_addres <= 9)
			ft_putchar_fd((ptr_addres + '0'), 1);
		else
			ft_putchar_fd((ptr_addres - 10 + 'a'), 1);
	}
}

int print_ptr(unsigned long long ptr)
{
    int len;

    len = 0;
    len += write(1, "0x", 2);
    if (ptr == 0)
        len += write(1, "0", 1);
    else
    {
        put_ptr(ptr);
        len += get_ptr_len(ptr);
    } 
    return (len);
}