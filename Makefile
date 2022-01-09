NAME			= so_long

NAME_BON		= so_long_bonus

SRC_DIR			= src/

SRCS			= $(shell find ${SRC_DIR} -name *.c)
OBJS			= $(patsubst %.c,%.o,${SRCS})
D_FILES			= $(patsubst %.c,%.d,${SRCS})

SRC_BON_DIR		= src_bonus/

SRCS_BON		= $(shell find ${SRC_BON_DIR} -name *.c)
OBJS_BON		= $(patsubst %.c,%.o,${SRCS_BON})
D_FILES_BON		= $(patsubst %.c,%.d,${SRCS_BON})

CFLAGS			= -Wall -Werror -Wextra -O2 -MMD

INCLUDES		= -I includes/ -I ${MINILIBIX_DIR} -I ${LIBFT_DIR}

INCLUDES_BON	= -I includes_bonus/ -I ${MINILIBIX_DIR} -I ${LIBFT_DIR}

MINILIBIX_DIR	= ./minilibx

GREENBG			= \033[42m

NOBG			= \033[0m

GREENTXT		= \033[1;32m

NOCOLORTXT		= \033[0m

LIBFT_DIR		= libft/

LIBS			= -lmlx -L${MINILIBIX_DIR} -L${LIBFT_DIR} -lft

%.o:			%.c Makefile
				${CC} ${CFLAGS} -c $< -o $@  ${INCLUDES} ${INCLUDES_BON}

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

bonus:			${NAME_BON}

$(NAME_BON):	${OBJS_BON}
				echo  "${GREENTXT}Compiling MINILIB${NOCOLORTXT}\n"
				make -sC  $(MINILIBIX_DIR)
				echo  "${GREENTXT}MINILIB is compiled${NOCOLORTXT}\n"
				echo  "${GREENTXT}Compiling LIBFT${NOCOLORTXT}\n"
				make -sC ${LIBFT_DIR}
				echo  "${GREENTXT}LIBFT is compiled${NOCOLORTXT}\n"
				${CC}  ${CFLAGS} ${OBJS_BON} ${LIBS} -framework OpenGL -framework AppKit -o $(NAME_BON)
				mv $(MINILIBIX_DIR)/libmlx.dylib .
				echo "${GREENTXT}solong is compiled${NOCOLORTXT}\n"

clean:
				rm -rf ${OBJS} ${D_FILES}
				rm -rf ${OBJS_BON} ${D_FILES_BON}
				echo "${GREENTXT}Cleaning complete${NOCOLORTXT} \n"

fclean:			clean
				${RM} ${NAME}
				${RM} ${NAME_BON}
				${RM} libmlx.dylib
				make fclean -sC ${MINILIBIX_DIR}
				make fclean -sC ${LIBFT_DIR}
				echo "${GREENTXT}Full cleaning is complete too${NOCOLORTXT} \n"

re:				fclean all

include $(wildcard $(D_FILES))

.PHONY:			all clean fclean re bonus
.SILENT:		all clean fclean re bonus $(NAME)
