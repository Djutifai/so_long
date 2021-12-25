NAME			= solong

SRC_FILES		= inits.c main.c

GNL_FILES		= get_next_line_utils.c get_next_line.c

HELPERS_FILES	= basic_funcs.c

MAP_FILES		= validator.c parser.c

REND_FILES		= render.c

MOVE_FILES		= pl_move.c

SRC_DIR			= src/

GNL_DIR			= src/gnl/

HELPERS_DIR		= src/helpers/

MAP_DIR			= src/map/

REND_DIR		= src/render/

MOVE_DIR		= src/movement/

SRCS			= ${addprefix ${HELPERS_DIR}, ${HELPERS_FILES}}
SRCS			+= $(addprefix ${SRC_DIR}, ${SRC_FILES})
SRCS			+= ${addprefix ${MOVE_DIR}, ${MOVE_FILES}}
SRCS			+= $(addprefix ${REND_DIR}, ${REND_FILES})
SRCS			+= $(addprefix ${GNL_DIR}, ${GNL_FILES})
SRCS			+= $(addprefix ${MAP_DIR}, ${MAP_FILES})

SRC_SUBDIR		= . map/ render/ gnl/ helpers/ movement/

OBJ_DIR			= ./objs/

OBJ_DIRS		= $(addprefix ${OBJ_DIR}, ${SRC_SUBDIR})

OBJS			= $(patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRCS})

CFLAGS			= -Wall -Werror -Wextra -O2 -MMD

INCLUDES		= -I includes/ -I ${MINILIBIX_DIR} -I ${LIBFT_DIR}

MINILIBIX_DIR	= ./minilibx

GREENBG			= \033[42m

NOBG			= \033[0m

GREENTXT		= \033[1;32m

NOCOLORTXT		= \033[0m

LIBFT_DIR		= libft/

LIBS			= -lmlx -L${MINILIBIX_DIR} -L${LIBFT_DIR} -lft

all:			${NAME}

$(NAME):		${OBJS}
				echo  "${GREENTXT}Compiling MINILIB${NOCOLORTXT}\n"
				make -sC  $(MINILIBIX_DIR)
				echo  "${GREENTXT}MINILIB is compiled${NOCOLORTXT}\n"
				echo  "${GREENTXT}Compiling LIBFT${NOCOLORTXT}\n"
				make -sC ${LIBFT_DIR}
				echo  "${GREENTXT}LIBFT is compiled${NOCOLORTXT}\n"
				${CC}  ${CFLAGS} ${OBJS} ${LIBS} -framework OpenGL -framework AppKit -o $(NAME)
				mv $(MINILIBIX_DIR)/libmlx.dylib .
				echo "${GREENTXT}solong is compiled${NOCOLORTXT}\n"


${OBJ_DIRS}:
				mkdir -p $@

include $(wildcard $(OBJ_DIR)*.d) $(wildcard $(OBJ_DIR)render/*.d) $(wildcard ${OBJ_DIR}gnl/*.d) \
	$(wildcard ${OBJ_DIR}parser/*.d) $(wildcard ${OBJ_DIR}map/*.d) $(wildcard ${OBJ_DIR}movement/*.d)
#hope i will undefstand how to make Makefile dependency with prerequesite -.-
${OBJ_DIR}%.o:	${SRC_DIR}%.c $(OBJ_DIRS) Makefile
				${CC} ${CFLAGS} -c $< -o $@  ${INCLUDES}

clean:
				rm -rf ${OBJ_DIR}
				echo "${GREENTXT}Cleaning complete${NOCOLORTXT} \n"

fclean:			clean
				${RM} ${NAME}
				${RM} libmlx.dylib
				make clean -sC ${MINILIBIX_DIR}
				make clean -sC ${LIBFT_DIR}
				echo "${GREENTXT}Full cleaning is complete too${NOCOLORTXT} \n"

re:				fclean all

.PHONY:			all clean fclean re
.SILENT:		all clean fclean re
