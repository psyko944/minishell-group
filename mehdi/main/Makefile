# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 17:48:07 by mekherbo          #+#    #+#              #
#    Updated: 2024/06/04 20:57:59 by mekherbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = ft_env.c \
history.c \
utils.c \
parser/ast/ast.c \
parser/tokenize/cut_command.c \
parser/tokenize/free_tokens.c \
parser/tokenize/get_token.c \
parser/tokenize/new_token.c \
parser/tokenize/quotes.c \
parser/tokenize/tokenize.c \
tests/unit_test_main.c \
tests/unit_test_mehdi.c \
tests/unit_tests_armand.c \
tests/armand/print_ast.c \
tests/armand/test_tokenize.c \

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

cc = gcc

RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = minishell.h
CFLAGS = -Wall -Wextra -Werror -g3

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

#$(OBJS) : $(HEADER)

all:	$(NAME)
		@echo "$(GREEN)minishell compiled!$(DEF_COLOR)"

.c.o:
	${CC} ${CFLAGS} -I include -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

-include $(SRCS:.c=.d)

clean:
	$(RM) $(NAME)
	@echo "$(BLUE)minishell object files cleaned!$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for minishell!$(DEF_COLOR)"

.PHONY: all clean fclean re libft
