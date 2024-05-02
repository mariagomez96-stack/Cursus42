# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marigome <marigome@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 12:27:23 by marigome          #+#    #+#              #
#    Updated: 2024/05/02 12:30:32 by marigome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = \
	ft_found_c.c\
	ft_found_d.c\
	ft_found_p.c\
	ft_found_s.c\
	ft_found_u.c\
	ft_found_upperX.c\
	ft_found_x.c\
	printf.c\

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