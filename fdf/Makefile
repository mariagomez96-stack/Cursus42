# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 				= fdf

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

CHECKER_DIR				= ./checker
ERROR_DIR				= ./error
MAPS_DIR				= ./maps
PROJECTION_DIR			= ./projection
SRC_DIR					= ./src
SRC_CAM_DIR				=./src_cam
SRC_MAP_DIR				= ./src_map
LIBRARIES				= ./libs
OBJ_DIR					= ./obj
LIBFT_DIR				= libft
PRINTFT_DIR				= printf
GNL_DIR					= gnl
INCLUDES_DIR			= ./includes
MLX42_LIB				= ./MLX42/lib
MLX42_INCLUDE			= ./MLX42/include/MLX42

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

CHECKER			= ${CHECKER_DIR}/check_arg.c

ERROR			= ${ERROR_DIR}/ft_error_and_free.c

PROJECTION		= ${PROJECTION_DIR}/draw.c \
					${PROJECTION_DIR}/ft_angles.c \
					${PROJECTION_DIR}/conf_events.c \
					${PROJECTION_DIR}/project.c \
					${PROJECTION_DIR}/pixel.c

SRC 				= ${SRC_DIR}/fdf.c \
						${SRC_DIR}/init_mlx.c

SRC_CAM				= ${SRC_CAM_DIR}/cam.c

SRC_MAP			= ${SRC_MAP_DIR}/init_map.c \
					${SRC_MAP_DIR}/utils_map.c \

GNL					= ${LIBRARIES}/${GNL_DIR}/get_next_line.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_bonus.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils_bonus.c


OBJ_CHECKER				= $(patsubst ${CHECKER_DIR}/%.c, ${OBJ_DIR}/%.o, ${CHECKER})
OBJ_ERR				= $(patsubst ${ERROR_DIR}/%.c, ${OBJ_DIR}/%.o, ${ERROR})
OBJ_PROJECTION				= $(patsubst ${PROJECTION_DIR}/%.c, ${OBJ_DIR}/%.o, ${PROJECTION})
OBJ_SRC				= $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_SRC_CAM				= $(patsubst ${SRC_CAM_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC_CAM})
OBJ_SRC_MAP				= $(patsubst ${SRC_MAP_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC_MAP})

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

${NAME}: ftlibft ftprintf ${LIBMLX42_A} ${OBJ_CHECKER} ${OBJ_GNL} \
									${OBJ_ERR} ${OBJ_PROJECTION} \
									${OBJ_SRC} ${OBJ_SRC_CAM} ${OBJ_SRC_MAP}

	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_CHECKER} ${OBJ_GNL} ${OBJ_ERR} \
									${OBJ_PROJECTION} ${OBJ_SRC} \
									${OBJ_SRC_CAM} ${OBJ_SRC_MAP} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${CHECKER_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${LIBRARIES}/${GNL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${ERROR_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${PROJECTION_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${SRC_CAM_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${SRC_MAP_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

ftlibft:
	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} all

ftprintf:
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} all


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
	@echo "$(YELLOW)Removing object files ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} clean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} clean
	@$(RM) ${OBJ_DIR}/*.o

	@echo "$(RED)Object files removed $(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Removing binaries ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} fclean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} fclean
	@${RM} ${NAME} ${NAME_BONUS}

	@echo "$(RED)Binaries removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all ftlibft ftprintf ftexamft clean fclean bonus re
