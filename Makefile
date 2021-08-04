NAME = libftprintf.a

CFLAGS := -Wall -Wextra -Werror

CC := cc

SRC = 	./srcs/conv1_c_s_d_u_p.c \
		./srcs/conv2_x_percentage.c \
		./srcs/evaluate_flags.c \
		./srcs/flags_spc_zero_-_width_+.c \
		./srcs/ft_printf.c \
		./srcs/libft.c \
		./srcs/libft_2.c \
		./srcs/struct.c \
		./srcs/prepare_tab.c \
		./srcs/zero.c \
		./srcs/flags_precision.c\
		./srcs/print_alignment.c\
		./srcs/aux_conv.c\


OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $?

bonus: $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean clean all

.PHONY: all clean fclean re