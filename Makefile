FILES		= inits.c main.c

SRCDIR		= src/

SRC			= ${addprefix ${SRCDIR}, ${FILES}}

OBJ         = ${SRC:.c=.o}

SRCD		= ${patsubst %.c,%.d,${SRC}}

CFLAGS   = -Wall -Werror -Wextra

INCLUDES    = includes/

NAME		= solong

%.o:        %.c Makefile
			${CC} ${CFLAGS} -c $< -o $@ -I${INCLUDES} -MMD 

all:		${NAME}

$(NAME):	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			${RM} ${OBJ} ${SRCD}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re