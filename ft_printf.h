#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	print_hex(unsigned int num, const char format);

int print_str(char *str);

int print_nbr(int n);

int ft_printf(const char *format, ...);

int print_unsigned(unsigned int n);

int print_ptr(unsigned long long ptr);

#endif