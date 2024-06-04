CC			=	cc

CCL			=	ar rc

FLAGS 		=	-Wall -Wextra -Werror -fPIC

SRCPATH 	=	././

SRCS 		=	$(SRCPATH)ft_tolower.c		\
				$(SRCPATH)ft_toupper.c		\
				$(SRCPATH)ft_memcpy.c		\
				$(SRCPATH)ft_putnbr_fd.c	\
				$(SRCPATH)ft_strdup.c		\
				$(SRCPATH)ft_strlen.c		\
				$(SRCPATH)ft_substr.c		\
				$(SRCPATH)ft_itoa.c			\
				$(SRCPATH)ft_memmove.c		\
				$(SRCPATH)ft_putstr_fd.c	\
				$(SRCPATH)ft_striteri.c		\
				$(SRCPATH)ft_strmapi.c		\
				$(SRCPATH)ft_bzero.c		\
				$(SRCPATH)ft_math.c			\
				$(SRCPATH)ft_memset.c		\
				$(SRCPATH)ft_split.c		\
				$(SRCPATH)ft_strjoin.c		\
				$(SRCPATH)ft_strncmp.c		\
				$(SRCPATH)ft_calloc.c		\
				$(SRCPATH)ft_memchr.c		\
				$(SRCPATH)ft_putchar_fd.c	\
				$(SRCPATH)ft_strchr.c		\
				$(SRCPATH)ft_strrchr.c		\
				$(SRCPATH)ft_strlcat.c		\
				$(SRCPATH)ft_strnstr.c		\
				$(SRCPATH)ft_isalnum.c		\
				$(SRCPATH)ft_isalpha.c		\
				$(SRCPATH)ft_isascii.c		\
				$(SRCPATH)ft_isdigit.c		\
				$(SRCPATH)ft_isprint.c		\
				$(SRCPATH)ft_isspace.c		\
				$(SRCPATH)ft_memcmp.c		\
				$(SRCPATH)ft_putendl_fd.c	\
				$(SRCPATH)ft_strcpy.c		\
				$(SRCPATH)ft_strlcpy.c		\
				$(SRCPATH)ft_strtrim.c		\
				$(SRCPATH)ft_atoi.c			\
				$(SRCPATH)ft_puthex_fd.c	\
				$(SRCPATH)ft_putptr.c		\
				$(SRCPATH)ft_realloc.c		\
				$(SRCPATH)ft_matrix.c	\
				$(SRCPATH)ft_strjoin2.c	\
				$(SRCPATH)ft_strjoin3.c	\
				$(SRCPATH)get_next_line.c	\
				
SRCBONUS	=	$(SRCPATH)ft_lstnew.c		\
				$(SRCPATH)ft_lstadd_front.c	\
				$(SRCPATH)ft_lstsize.c		\
				$(SRCPATH)ft_lstlast.c		\
				$(SRCPATH)ft_lstadd_back.c	\
				$(SRCPATH)ft_lstdelone.c	\
				$(SRCPATH)ft_lstclear.c		\
				$(SRCPATH)ft_lstiter.c		\
				$(SRCPATH)ft_lstmap.c		\


INCLUDEPATH =	./

OBJ 		=	$(SRCS:.c=.o)

OBJBONUS	=	$(SRCBONUS:.c=.o)

NAME 		=	libft.a

$(NAME): $(OBJ)
	$(CCL) $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJ) $(OBJBONUS)
	
fclean: clean
	rm -f $(NAME)

all: $(NAME)

bonus:	$(OBJ) $(OBJBONUS)
	$(CCL) $(NAME) $(OBJ) $(OBJBONUS)

re: fclean all

.PHONY: clean fclean all re

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(SRCBONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJBONUS)
