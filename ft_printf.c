#include "ft_printf.h"


static int check_format(va_list args, const char format)
{
    if (format == '%')
		return (write(1, "%", 1));
	else if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (format == 's')
		return (print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (print_ptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (print_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (print_hex(va_arg(args, unsigned int), format));
	else if (format == 'X')
		return (print_hex(va_arg(args, unsigned int), format));
	return (0);
}

int ft_printf(const char *format, ...)
{
    int		i;
	int		len;
	va_list	args;

	if (!format)
		return (0);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += check_format(args, format[i]);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}