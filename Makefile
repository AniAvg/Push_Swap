NAME = push_swap

SRCS = ./sources/validation.c ./sources/lst_functions.c ./sources/utils.c \
		./sources/push_swap.c ./sources/push_swap_ops.c ./sources/rotate_revrotate_ops.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I ./includes -I ./libft  $(OBJS) -L ./libft -lft -o $(NAME)

$(LIBFT) :
	make -C ./libft all

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -I./libft -c -o $@ $<

clean :
	make -C ./libft clean
	rm -f $(OBJS)

fclean : clean
	make -C ./libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
