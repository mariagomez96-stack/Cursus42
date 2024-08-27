# ***** NAMES ***************************************************************** #

NAME = push_swap

# ***** APARIENCE ************************************************************* #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
BLACK = \033[0;99m
ORANGE = \033[38;5;209m
BROWN = \033[38;2;184;143;29m
DARK_GRAY = \033[38;5;234m
MID_GRAY = \033[38;5;245m
DARK_GREEN = \033[38;2;75;179;82m
DARK_YELLOW = \033[38;5;143m

SRCS = push_swap.c \
		checker_args.c \
		error_stack.c \
		get_index.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		stack.c \
		swap.c \
		utils.c \
		sort_three.c \
		sort_numbers.c \
		ft_get_target.c \
		ft_get_position.c \
		cost.c \
		do_move.c

LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH = ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_PATH)/libftprintf.a

INCLUDE_DIR = .
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -I$(FT_PRINTF_PATH)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

%.o: %.c
		@echo "$(BLUE) ◎ $(YELLOW)Compiling $(RED)→ $(GREEN)$< $(DEF_COLOR)"
		@$(CC) $(CFLAGS) -c $< -o $@

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) -o $(NAME)
	@echo "\n$(GREEN) Created $(NAME) ✓$(DEF_COLOR)\n"

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF_ARCHIVE):
	$(MAKE) -C $(FT_PRINTF_PATH)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(FT_PRINTF_PATH) fclean
	@echo "\n$(GRAY) ◎ $(RED)All objects and executable cleaned successfully $(GRAY)◎$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
