# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marigome <marigome@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 13:16:09 by marigome          #+#    #+#              #
#    Updated: 2024/04/25 15:37:34 by marigome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = \


OBJ = $(FILES:.c=.o)
RM = @rm -f
FLAGS =	-Wall -Werror -Wextra
$(NAME): $(FILES) $(OBJ)
	@echo "Working..."
	@gcc -c $(FLAGS) $(FILES)
	@echo "$(NAME) created"
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)
clean:
	@echo "Removing.o"
	${RM} $(OBJ)
fclean: clean
	${RM} $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus