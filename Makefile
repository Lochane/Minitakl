CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

SRCDIR_S = src_server
SRC_S = $(SRCDIR_S)/server.c \
OBJ_S = $(SRC_S:.c=.o)
 
SRCDIR_C = src_client
SRC_S = $(SRCDIR_C)/client.c \
OBJ_C = $(SRC_C:.c=.o)

C_NAME = client
S_NAME = serveur

LIBPATH = ./libft/libft.a

all:	$(C_NAME) $(S_NAME)

$(S_NAME):	$(OBJ_S) | lib
		$(CC) $(CFLAGS) -o $@ $(OBJ_S) $(LIBPATH)

$(C_NAME):	$(OBJ_C) | lib
		$(CC) $(CFLAGS) -o $@ $(OBJ_C) $(LIBPATH) 

lib:
	@make -C ./libft

clean:
		$(RM) $(OBJ_C) $(OBJ_S)
		@make clean -C ./libft

fclean:	clean
		$(RM) $(C_NAME) $(S_NAME)
		@make fclean -C ./libft

re:	fclean all

.PHONY: all clean fclean re
	