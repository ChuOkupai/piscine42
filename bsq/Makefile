SRCS		= ft_find_biggest_square.c \
			  ft_is_valid.c \
			  ft_file_load.c \
			  main.c

OBJS		= $(addprefix srcs/, ${SRCS:.c=.o})

HEADERS		= bsq.h \
			  ft.h

NAME		= bsq

CFLAGS		= -Wall -Wextra -Werror -Ofast

all:		${NAME}

${NAME}:	${OBJS}
			gcc ${CFLAGS} ${OBJS} -o $@

.c.o:
			gcc ${CFLAGS} -I./includes -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
