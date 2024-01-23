CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftprintf.a

SRCS = ft_printf.c print_hex.c print_str.c print_nbr.c print_unsigned.c print_ptr.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re