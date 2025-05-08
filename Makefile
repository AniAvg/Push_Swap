NAME = push_swap
BONUS_NAME = checker

SRCS = ./sources/validation.c ./sources/validation_utils.c ./sources/stack_ops.c \
		./sources/rotate_revrotate_ops.c ./sources/push_swap_ops.c ./sources/utils.c \
		./sources/fill_stack.c ./sources/sort.c ./sources/final_sort.c ./sources/simple_sort.c \
		./sources/push_swap.c

SRCS_BONUS = ./bonus/validation_bonus.c ./bonus/validation_utils_bonus.c ./bonus/stack_ops_bonus.c \
			./bonus/rotate_revrotate_ops_bonus.c ./bonus/push_swap_ops_bonus.c \
			./bonus/utils_bonus.c ./bonus/fill_stack_bonus.c ./bonus/push_swap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I ./includes -I ./libft  $(OBJS) -L ./libft -lft -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -I ./includes -I ./libft  $(OBJS_BONUS) -L ./libft -lft -o $(BONUS_NAME)

$(LIBFT) :
	make -C ./libft all

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -I./libft -c -o $@ $<

clean :
	make -C ./libft clean
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean : clean
	make -C ./libft fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all

.PHONY : all bonus clean fclean re
