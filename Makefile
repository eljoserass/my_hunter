##
## EPITECH PROJECT, 2020
## my_printf
## File description:
## only makefile
##

BIN_NAME=	my_hunter

BIN_PATH=	src/

BIN_SRC	=	main.c	 					\
			my_putstr.c 				\
			my_put_nbr.c 				\
			my_init_struct.c 			\
			window.c 					\
			game_loop.c 				\
			draw.c 						\
			refresh.c 					\
			events.c 					\

BIN_SRCS=	$(addprefix $(BIN_PATH), $(BIN_SRC))

BIN_OBJS=	$(BIN_SRCS:.c=.o)

GCC		=	gcc

CFLAGS	+=	-I./include

all:  $(BIN_NAME)

$(BIN_NAME):	$(BIN_OBJS)
	$(GCC) -o $(BIN_NAME) $(BIN_OBJS) -l csfml-window -l csfml-graphics -l csfml-system

clean:
	$(RM) $(BIN_OBJS)

fclean: clean
	$(RM) $(BIN_NAME)

re: fclean all