CDIR = ./srcs
HDIR = ./includes

CFILES = $(CDIR)/ft_putchar.c \
	  $(CDIR)/ft_swap.c \
	  $(CDIR)/ft_putstr.c \
	  $(CDIR)/ft_strlen.c \
	  $(CDIR)/ft_strcmp.c

OFILES = $(CFILES:.c=.o)

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(HDIR)

all: $(NAME)

# target: reprerequisites
# recipe
$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

# % » wildcard » eg. *.c
# $< » input file (the source file)
# $@ » output file (the object file)
$(CDIR)/%.o: $(CDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
