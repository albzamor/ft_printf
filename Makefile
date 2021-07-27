NAME = libftprintf.a

CFLAGS := -Wall -Wextra -Werror

CC := cc

SRC = 	./srcs/conv1_c_s_d_u_p.c \
		./srcs/conv2_x_percentage.c \
		./srcs/evaluate.c \
		./srcs/flags.c \
		./srcs/ft_printf.c \
		./srcs/libft.c \
		./srcs/struct.c \
		./srcs/prepare_tab.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean clean all

.PHONY: all clean fclean re