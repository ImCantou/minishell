SRCDIR	=	Srcs

SRCS		= $(addprefix $(SRCDIR)/, perror_exit.c\
									main.c\
									minishell.c\
									searchenv.c\
									keylist_tools.c\
									parsing.c\
									parsing_tools.c\
									simple_cmd_cut.c\
									simple_cmd_cut_tools.c\
									tilde_exp.c\
									param_exp.c\
									field_split.c\
									pathname_exp.c\
									pathname_exp_tools.c\
									wildcard_exp.c\
									dirlist_tools.c\
									do_expansion.c\
									quote_removal.c\
									heredocfile.c\
									heredoctools.c\
									heredocmain.c\
									redirection.c\
									exec.c\
									exectools.c\
									pipex.c\
									wildcard_exp2.c\
									dirlist_tools2.c\
									envl_to_envp.c)
								

BIDIR		=	Built-ins

BISRCS		= $(addprefix $(BIDIR)/, cd.c\
									echo.c\
									env.c\
									exit.c\
									export.c\
									pwd.c\
									unset.c)

OBJDIR		=	Objs

OBJS		= $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))

BIOBJS		= $(addprefix $(OBJDIR)/,$(notdir $(BISRCS:.c=.o)))

INCLUDES	= 

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-I.${INCLUDES} -Wall -Wextra -Werror

NAME		=	minishell

LIBFTDIR	=	libft

LIBFT		=	libft/libft.a

all:	${NAME}

${LIBFT}:
		@make bonus --silent -C ${LIBFTDIR}
		@printf "`tput bold`\033[92m[SUCCESS]\033[0;37m: `tput bold`Compilating \033[1;94m${LIBFTDIR}\033[0;37m/$(notdir $(LIBFT))\033[1;37m to library done.\n`tput sgr0`"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@$(CC) -c $(CFLAGS) $< -o $@
			@printf "`tput bold`\033[92m[SUCCESS]\033[0;37m: `tput bold`Compilating \033[1;94m${SRCDIR}\033[0;37m/$(notdir $<)\033[1;37m to object done.\n`tput sgr0`"

$(OBJDIR)/%.o:	$(BIDIR)/%.c
			@$(CC) -c $(CFLAGS) $< -o $@
			@printf "`tput bold`\033[92m[SUCCESS]\033[0;37m: `tput bold`Compilating \033[1;94m${BIDIR}\033[0;37m/$(notdir $<)\033[1;37m to object done.\n`tput sgr0`"

${NAME}:	$(LIBFT) ${OBJS} ${BIOBJS}
		@${CC} ${CFLAGS} -g3 ${OBJS} ${BIOBJS} $(LIBFT) -o ${NAME} -L/usr/local/lib -I/usr/local/include -lreadline
		@printf "`tput bold`\033[92m[SUCCESS]\033[0;37m: `tput bold`Program \033[92m$@\033[0m `tput bold`ready for execution.\n`tput sgr0`"


clean:
		@make fclean --silent -C ${LIBFTDIR}
		@printf "`tput bold`\033[92m[SUCCESS]\033[0;37m: `tput bold`Library cleaning done.\n`tput sgr0`"
		@${RM} ${OBJS} 
		@${RM} ${BIOBJS}
		@printf "`tput bold`\033[92m[SUCCESS]\033[0;37m: `tput bold`Objects cleaning done.\n`tput sgr0`"

fclean:	clean
		@${RM} ${NAME}
		@printf "`tput bold`\033[92m[SUCCESS]\033[0;37m: `tput bold`Full clean done.\n`tput sgr0`"

test: all
		@printf "`tput bold`\033[1;93m[IN PROGRESS]\033[0;37m: `tput bold`Starting \e[38;5;82mM\e[38;5;118mi\e[38;5;121mn\e[38;5;121mi\e[38;5;159ms\e[38;5;86mh\e[38;5;44me\e[38;5;74ml\e[38;5;69ml\e[38;5;7m with valgrind ...\n`tput sgr0`"
		@valgrind --leak-check=full \
					--show-leak-kinds=all \
					--suppressions=./.readline.supp \
					--track-origins=yes \
					--track-fds=yes \
								./minishell

re:	fclean 
	@make all

.PHONY:	clean fclean all re

#.SILENT:	clean fclean ${NAME} ${OBJS}