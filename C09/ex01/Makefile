CFILES = ./srcs/ft_putchar.c \
	  ./srcs/ft_swap.c \
	  ./srcs/ft_putstr.c \
	  ./srcs/ft_strlen.c \
	  ./srcs/ft_strcmp.c

OFILES = $(CFILES:.c=.o)
	
INCLUDES = ./includes

NAME = libft.a
CC = gcc
CFLAGS = -I $(INCLUDES) -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
