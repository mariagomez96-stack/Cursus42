# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 				= cub3D

# ══ Colors ══════════════════════════════════════════════════════════════════ #
#    ------                                                                    #

DEL_LINE 			= \033[2K
ITALIC 				= \033[3m
BOLD 				= \033[1m
DEF_COLOR 			= \033[0;39m
GRAY 				= \033[0;90m
RED 				= \033[0;91m
GREEN 				= \033[0;92m
YELLOW 				= \033[0;93m
BLUE 				= \033[0;94m
MAGENTA 			= \033[0;95m
CYAN 				= \033[0;96m
WHITE 				= \033[0;97m
BLACK 				= \033[0;99m
ORANGE 				= \033[38;5;209m
BROWN 				= \033[38;2;184;143;29m
DARK_GRAY 			= \033[38;5;234m
MID_GRAY 			= \033[38;5;245m
DARK_GREEN 			= \033[38;2;75;179;82m
DARK_YELLOW 		= \033[38;5;143m

# ══ Compilation══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

CC 					= clang
AR 					= ar rcs
RM 					= rm -f
MK 					= make -C
MKD					= mkdir -p
MCL 				= make clean -C
MFCL 				= make fclean -C
MK_					= && make

# ══ Directories ═════════════════════════════════════════════════════════════ #
#    -----------                                                               #

READ_DIR				= ./read_map
MAPS_DIR				= ./maps
MAPS_ERR_DIR			= ./maps_error
LIBRARIES				= ./libs
OBJ_DIR					= ./obj
LIBFT_DIR				= libft
PRINTFT_DIR				= printf
GNL_DIR					= gnl
INCLUDES_DIR			= ./includes
MLX42_LIB				= ./MLX42/lib
MLX42_INCLUDE			= ./MLX42/include/MLX42
PARSING_DIR				= ./parser
PLAY_DIR				= ./play
INIT_DIR				= ./init


# ══ Bonus Directories ═══════════════════════════════════════════════════════ #
#    -----------------                                                         #

# SRC_BONUS_DIR		= ./checker_bonus/src_bonus
# GNL_BONUS_DIR		= ./checker_bonus/gnl_bonus
# INCLUDES_BONUS_DIR	= ./checker_bonus/includes_bonus

# ══ Library Archives ════════════════════════════════════════════════════════ #
#    ----------------                                                          #

LIBFT_A				= ${LIBRARIES}/${LIBFT_DIR}/libft.a
PRINTFT_A			= ${LIBRARIES}/${PRINTFT_DIR}/libftprintf.a
#EXAMFT_A			= ${LIBRARIES}/${EXAMFT_DIR}/libexamft.a
LIBMLX42_A			= ${MLX42_LIB}/libmlx42.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CFLAGS 				= -Wall -Werror -Wextra
IFLAGS				= -I${INCLUDES_DIR} -I${MLX42_INCLUDE}
LFLAGS				= -L${LIBRARIES}/${LIBFT_DIR} -lft \
					  -L${LIBRARIES}/${PRINTFT_DIR} -lftprintf \
					  -L$(MLX42_LIB) -lmlx42 -lglfw -ldl -lm -lpthread


# ══ Flags Bonus══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

# IFLAGS_BONUS		= -I${INCLUDES_BONUS_DIR}

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

GNL					= ${LIBRARIES}/${GNL_DIR}/get_next_line.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_bonus.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils_bonus.c

PARSING				= ${PARSING_DIR}/parser.c

PLAY				= ${PLAY_DIR}/main.c

INIT				= ${INIT_DIR}/init_structures.c \
       				${INIT_DIR}/init_walls_and_rays.c


READ = ${READ_DIR}/checker.c \
       ${READ_DIR}/error.c \
       ${READ_DIR}/manage_color.c \
       ${READ_DIR}/map.c \
       ${READ_DIR}/utils.c \
       ${READ_DIR}/textures.c \
	   ${READ_DIR}/checker_2.c \
	   ${READ_DIR}/free.c 



OBJ_PARSING			= $(patsubst ${PARSING_DIR}/%.c, ${OBJ_DIR}/%.o, ${PARSING})
OBJ_PLAY			= $(patsubst ${PLAY_DIR}/%.c, ${OBJ_DIR}/%.o, ${PLAY})
OBJ_INIT			= $(patsubst ${INIT_DIR}/%.c, ${OBJ_DIR}/%.o, ${INIT})
OBJ_READ			= $(patsubst ${READ_DIR}/%.c, ${OBJ_DIR}/%.o, ${READ})
OBJ_GNL				= $(patsubst ${LIBRARIES}/${GNL_DIR}/%.c, ${OBJ_DIR}/%.o, \
						${GNL})

# ══ Sources Bonus ═══════════════════════════════════════════════════════════ #
#    -------------                                                             #

# SRC_BONUS			= ${SRC_BONUS_DIR}/checker_bonus.c
# GNL_BONUS			= ${GNL_BONUS_DIR}/get_next_line_bonus.c \
# 						${GNL_BONUS_DIR}/get_next_line_utils_bonus.c

# OBJ_SRC_BONUS		= $(patsubst ${SRC_BONUS_DIR}/%.c, ${OBJ_DIR}/%.o, \
# 						${SRC_BONUS})
# OBJ_GNL_BONUS		= $(patsubst ${GNL_BONUS_DIR}/%.c, ${OBJ_DIR}/%.o, \
# 						${GNL_BONUS})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}

${NAME}: ftlibft ftprintf ${LIBMLX42_A} ${OBJ_PARSING} ${OBJ_GNL} \
									${OBJ_PLAY} ${OBJ_INIT} \
									${OBJ_READ}

	@echo "$(YELLOW)Compiling ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_PARSING} ${OBJ_GNL} \
									${OBJ_PLAY} ${OBJ_INIT} \
									${OBJ_READ} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${PARSING_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${LIBRARIES}/${GNL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${PLAY_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${INIT_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${READ_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

ftlibft:
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${LIBFT_DIR} all

ftprintf:
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${PRINTFT_DIR} all


# bonus: ${NAME_BONUS}

# ${NAME_BONUS}: ftlibft ftprintf ftexamft ${OBJ_ERR} ${OBJ_INT} \
# 											${OBJ_MOV} ${OBJ_SRT} ${OBJ_UTL} \
# 											${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS}
# 	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
# 	@${CC} ${CFLAGS} ${IFLAGS} ${IFLAGS_BONUS} -o ${NAME_BONUS} \
# 			${OBJ_ERR} ${OBJ_INT} ${OBJ_MOV} ${OBJ_SRT} ${OBJ_UTL} \
# 			${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS} ${LFLAGS} ${IFLAGS_BONUS}
# 	@echo "$(GREEN) $(NAME_BONUS) all created ✓$(DEF_COLOR)"

# ${OBJ_DIR}/%.o: ${SRC_BONUS_DIR}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${GNL_BONUS_DIR}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	@echo "$(YELLOW)Removing object files!$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${LIBFT_DIR} clean
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${PRINTFT_DIR} clean
	@find ${OBJ_DIR} -name "*.o" -type f -delete
	@echo "$(RED)Object files removed! $(DEF_COLOR)"


fclean:	clean
	@echo "$(YELLOW)Removing binaries!$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${LIBFT_DIR} fclean
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${PRINTFT_DIR} fclean
	@${RM} ${NAME}
	@echo "$(RED)Binaries removed! $(DEF_COLOR)"


re:	fclean all

.PHONY : all ftlibft ftprintf ftexamft clean fclean bonus re
