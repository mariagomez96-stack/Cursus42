NAME = get_next_line.a

FILES = \
		get_next_line.c\
		get_next_line_utils.c\
	
OBJ = $(FILES:.c=.o)
RM = @rm -f
FLAGS =	-Wall -Werror -Wextra
$(NAME): $(FILES) $(OBJ)
	@gcc -c $(FLAGS) $(FILES)
bonus: $(OBJ)
	@ar rcs $(NAME) $(OBJ)
all: $(NAME)
clean:
	${RM} $(OBJ)
fclean: clean
	${RM} $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus