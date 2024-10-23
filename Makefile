# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:24:32 by nicolive          #+#    #+#              #
#    Updated: 2024/05/22 19:01:43 by najeuneh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Werror -Wextra 

PRINTF = ./ft_printf/libftprintf.a

PRINT = ./ft_printf

NAME = so_long

MY_SOURCES = ft_backtrack.c ft_move.c ft_secure.c ft_split.c main.c so_long.c so_long_util.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(MY_OBJECTS)
	$(MAKE) -C $(PRINT)
	cc -lmlx -framework OpenGL -framework Appkit  $(PRINTF) -o $(NAME) $(MY_OBJECTS)

$(MY_OBJECTS):
	$(CC) $(CFLAGS) ${@:.o=.c} -o $@

clean:
	$(MAKE) clean -C $(PRINT)
	${RM} ${MY_OBJECTS}


fclean: clean
	$(MAKE) fclean -C $(PRINT)
	${RM} ${NAME}

re: fclean all

.PHONY: fclean re clean all