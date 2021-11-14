SRV_SRC		=	server.c

CLI_SRC		=	client.c

SRV_OBJ		=	$(SRV_SRC:.c=.o)
CLI_OBJ		=	$(CLI_SRC:.c=.o)

SRV_NAME	=	server
CLI_NAME	=	client

NAME		=	minitalk
RM			=	rm -rf
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

$(NAME)	:	$(SRV_NAME) $(CLI_NAME)

$(SRV_NAME)	:	$(SRV_OBJ)
				$(CC) $(CFLAGS) $(SRV_OBJ) -o $(SRV_NAME)

$(CLI_NAME)	:	$(CLI_OBJ)
				$(CC) $(CFLAGS) $(CLI_OBJ) -o $(CLI_NAME)

all	:	 $(NAME)

clean	:	
			$(RM) $(SRV_OBJ) $(CLI_OBJ)

fclean	:	clean
			$(RM) $(SRV_NAME) $(CLI_NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
