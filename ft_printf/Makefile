SRCS =	ft_printf.c ft_printf_utils.c ft_now_flags.c ft_save_conver.c ft_chars.c \
		ft_sign_int.c ft_pointer.c ft_unsigned_int.c

SRCS_DIR = srcs/

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

BONUS_OBJS = ${addprefix ${SRCS_DIR}, ${BONUS:.c=.o}}

NAME = libftprintf.a

HEADER = ./srcs/ft_printf.h

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

%.o:%.c		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			ar rcs ${NAME} ${OBJS} $?

bonus:		${NAME}

all:		${NAME}

clean:		
			@${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all 