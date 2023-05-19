CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

C_SRC_DIR = src/src_client/
C_SRC = $(addprefix $(C_SRC_DIR), client.c)
C_OBJ = $(C_SRC:.c=.o)

S_SRC_DIR = src/src_server/
S_SRC = $(addprefix $(S_SRC_DIR), server.c utils.c )
S_OBJ = $(S_SRC:.c=.o)

C_NAME = client
S_NAME = serveur

################ BONUS ##################

BONUS_NAMEC = client_bonus
BONUS_NAMES = server_bonus

C_SRC_DIR_BONUS = src_bonus/src_client_bonus/
C_SRC_BONUS = $(addprefix $(C_SRC_DIR_BONUS), client_bonus.c)
C_OBJ_BONUS = $(C_SRC_BONUS:.c=.o)

S_SRC_DIR_BONUS = src_bonus/src_server_bonus/
S_SRC_BONUS = $(addprefix $(S_SRC_DIR_BONUS), server_bonus.c utils_bonus.c utils2_bonus.c)
S_OBJ_BONUS = $(S_SRC_BONUS:.c=.o)

#########################################

LIBPATH = libft/libft.a

all:	$(C_NAME) $(S_NAME)

$(C_NAME):	$(C_OBJ) | lib
		$(CC) $(CFLAGS) -o $@ $(C_OBJ) $(LIBPATH) 

$(S_NAME):	$(S_OBJ) | lib
		$(CC) $(CFLAGS) -o $@ $(S_OBJ) $(LIBPATH)

lib:
	@make -C ./libft

################ BONUS ##################

bonus:	$(BONUS_NAMEC) $(BONUS_NAMES)

$(BONUS_NAMEC):	$(C_OBJ_BONUS) | lib
		$(CC) $(CFLAGS) -o $@ $(C_OBJ_BONUS) $(LIBPATH) 

$(BONUS_NAMES):	$(S_OBJ_BONUS) | lib
		$(CC) $(CFLAGS_BONUS) -o $@ $(S_OBJ_BONUS) $(LIBPATH)

#########################################

clean:
		$(RM) $(C_OBJ) $(S_OBJ) $(C_OBJ_BONUS) $(S_OBJ_BONUS)
		@make clean -C ./libft

fclean:	clean
		$(RM) $(C_NAME) $(S_NAME) $(BONUS_NAMES) $(BONUS_NAMEC)
		@make fclean -C ./libft

re:	fclean all

.PHONY: all clean fclean re
