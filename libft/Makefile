SRCS	= ft_spldeleteone.c ft_splinsert.c ft_spllen.c ft_pathjoin.c ft_spljoin.c ft_atol.c ft_atoi.c ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_strcmp.c ft_realloc.c get_next_line_bonus.c get_next_line_utils_bonus.c

SRCSBONUS	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c

OBJSBONUS	= ${SRCSBONUS:.c=.o}

OBJS	=	${SRCS:.c=.o}

NAME	=	libft.a

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

all:	${NAME}
		
clean:
	${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
	${RM} ${NAME}

bonus:	all ${OBJSBONUS}
	ar rc ${NAME} ${OBJSBONUS}

re:	fclean all

.PHONY:	all clean fclean re bonus
