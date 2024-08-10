# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 17:48:07 by mekherbo          #+#    #+#              #
#    Updated: 2024/08/10 13:44:32 by mekherbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = init/ft_env.c \
init/history.c \
init/prompt.c \
init/init.c \
utils.c \
signals.c \
parser/ast/ast.c \
parser/tokenize/cut_command.c \
parser/tokenize/free_tokens.c \
parser/tokenize/get_token.c \
parser/tokenize/new_token.c \
parser/tokenize/quotes.c \
parser/tokenize/tokenize.c \
parser/vars/concat.c \
parser/vars/cut.c \
parser/vars/replace.c \
parser/vars/remove_quotes.c \
wildcards/merge_wildcards.c \
wildcards/run_wildcards.c \
wildcards/wildcards.c \
exec/in_n_out.c \
exec/opener.c \
exec/here_doc.c \
parser/print_parse_err.c \
builtin/pwd_env.c \
builtin/cd.c \
exec/get_cmd.c \
exec/exec_cmd.c \
exec/exec_utils.c \
init/env_utils.c \
init/shlvl.c \
builtin/unset.c \
builtin/export.c \
builtin/parse_builtins.c\
builtin/echo.c\
builtin/exit.c \
main.c	\
tests/armand/print_ast.c \
tests/armand/test_tokenize.c \
# tests/unit_test_mehdi.c \
# tests/unit_test_main.c \
# tests/unit_tests_armand.c \

# colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = cc

RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = minishell.h
CFLAGS = -Wall -Wextra -Werror -g3

OBJS = $(SRCS:.c=.o)

all:	$(NAME)
		@echo "$(GREEN)🍻 Valhallashell is ready to be used!$(DEF_COLOR)"
		
$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

#$(OBJS) : $(HEADER)


.c.o:
	${CC} ${CFLAGS} -I include -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

-include $(SRCS:.c=.d)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	@echo "$(BLUE)minishell object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) have been deleted$(DEF_COLOR)"

re: fclean all
	@$(MAKE) -C $(LIBFT_DIR) re
	@echo "$(GREEN)Cleaned and rebuilt everything for minishell! ✔️$(DEF_COLOR)"

.PHONY: all clean fclean re libft
