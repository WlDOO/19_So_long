SOURCE = ft_all.c ft_printf.c  ft_putchar.c ft_putstr.c \

OBJETS = $(SOURCE:.c=.o)

BONUSOBJ = $(BONUS:.c=.o)

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

INCLUDE = ft_printf.h


all: $(NAME)

$(NAME): $(OBJETS)
	ar -src $(NAME) $(OBJETS)

$(OBJETS):
	gcc $(FLAG) -I $(INCLUDE) -c ${@:.o=.c} -o $@

clean:
	rm -f $(OBJETS) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
