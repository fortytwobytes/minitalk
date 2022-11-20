SERVER			=	server
SERVER_SRC		=	server.c
SERVER_OBJ		=	$(SERVER_SRC:.c=.o)

CLIENT			=	client
CLIENT_SRC		=	client.c 
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

UTILS			=	utils
UTILS_SRC		=	utils/ft_atoi.c utils/ft_printf.c utils/ft_putchar.c utils/ft_putmem.c utils/ft_putnbr_b.c utils/ft_putnbr.c utils/ft_putnbr_u.c utils/ft_putstr.c
UTILS_OBJ		=	$(UTILS_SRC:.c=.o)

CC				=	cc
FLAGS			= 	-Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)


$(SERVER): $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)

test :
	curl -s "https://pastebin.com/raw/yJCS9mcn" > test.sh

clean :
	@rm -f $(SERVER_OBJ) $(UTILS_OBJ) $(CLIENT_OBJ)

fclean : clean
	@rm -f $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re