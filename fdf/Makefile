# ══ Names ═══════════════════════════════════════════════════════════════════ #
NAME = fdf

# ══ Compilation and Commands════════════════════════════════════════════════ #
CC = clang
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
MKDIR = mkdir -p

# ══ Directories ═════════════════════════════════════════════════════════════ #
SRC_DIRS = src src_cam src_map projection events checker error
OBJ_DIR = obj
INCLUDES_DIR = includes
LIBFT_DIR = libs/libft
PRINTF_DIR = libs/printf
MLX42_LIB_DIR = MLX42/lib
MLX42_INCLUDE_DIR = MLX42/include/MLX42

# ══ Files ══════════════════════════════════════════════════════════════════ #
SRC = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# ══ Flags ══════════════════════════════════════════════════════════════════ #
IFLAGS = -I$(INCLUDES_DIR) -I$(MLX42_INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)
LFLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(MLX42_LIB_DIR) -lmlx42 -lglfw -ldl -lm -lpthread

# ══ Rules ══════════════════════════════════════════════════════════════════ #
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "Object files cleaned."

fclean: clean
	@$(RM) $(NAME)
	@echo "Binary and object files cleaned."

re: fclean all

# ══ Library Compilation Rules ══════════════════════════════════════════════ #
libft:
	@make -C $(LIBFT_DIR)

printf:
	@make -C $(PRINTF_DIR)

mlx:
	@make -C $(MLX42_LIB_DIR)
