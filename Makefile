NAME = libftprintf.a

OBJ_DIR = OBJS

SRCS = conversions2.c conversions.c error_handling.c ft_printf.c output_functions.c output_functions2.c string_functions.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

objs:
	cc -c $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
