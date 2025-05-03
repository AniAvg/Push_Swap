NAME = push_swap
BONUS = checker

SRCS = ./sources/validation.c ./sources/stack_ops.c ./sources/rotate_revrotate_ops.c \
		./sources/push_swap_ops.c ./sources/utils.c ./sources/fill_stack.c \
		./sources/sort.c ./sources/final_sort.c ./sources/simple_sort.c \
		./sources/push_swap.c

SRCS_BONUS = ./sources/validation_bonus.c ./sources/stack_ops_bonus.c \
			./sources/rotate_revrotate_ops_bonus.c ./sources/push_swap_ops_bonus.c \
			./sources/utils_bonus.c ./sources/fill_stack_bonus.c \
			./sources/sort_bonus.c ./sources/final_sort_bonus.c ./sources/simple_sort_bonus.c \
			./sources/push_swap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I ./includes -I ./libft  $(OBJS) -L ./libft -lft -o $(NAME)

$(BONUS): $(OBJS_BONUS)
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT) :
	make -C ./libft all

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -I./libft -c -o $@ $<

clean :
	make -C ./libft clean
	rm -f $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean : clean
	make -C ./libft fclean
	rm -f $(NAME)
	rm -f $(BONUS)

re : fclean all

.PHONY : all clean fclean re
