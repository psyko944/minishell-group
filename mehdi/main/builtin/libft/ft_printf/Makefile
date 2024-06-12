NAME = libftprintf.a 

SRCS = srcs/ft_print_char.c \
srcs/ft_print_int.c \
srcs/ft_print_string.c \
srcs/ft_print_ptr.c \
srcs/ft_print_hexa.c \
srcs/ft_print_unsigned.c \
srcs/ft_printf.c \
srcs/utils.c


# Colors

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

HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)   
		ar -rcs $(NAME) $(OBJS)
		
#$(OBJS) : $(HEADER)


all:	$(NAME)
		@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

.c.o:
	${CC} ${CFLAGS} -I include -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

-include $(SRCS:.c=.d)

clean:
	@$(RM) ${OBJS}
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)ft_printf.a have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY: all clean fclean re
