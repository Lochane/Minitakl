CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
HEADER = .

SRCDIR_S = src_server
SRC_S = server \
OBJ_S = $(addsuffix .o, ${SRC_S})
 
# SRCDIR_C = src_client
# SRC_S = $(SRCDIR_C)/client.c \
# OBJ_C = $(SRC_C:.c=.o)

C_NAME = client
S_NAME = serveur

LIBPATH = ./libft/libft.a

all:	$(S_NAME) #$(C_NAME) 

$(S_NAME):	$(OBJ_S) | lib
	 $(CC) $(CFLAGS) $(OBJ_S) -o $@ $(LIBPATH)

# $(C_NAME):	$(OBJ_C) | lib
# 		$(CC) $(CFLAGS) -o $@ $(OBJ_C) $(LIBPATH) 

%.o:%.c
	$(CC) -c $(FLAGS) $< -o $@ -I${HEADER}

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
	