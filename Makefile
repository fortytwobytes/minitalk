
SERVER   = server
CLIENT   = client
CC	     = cc
FLAGS    = -Wall -Werror -Wextra
RM	     = rm -f
SRCS     = server.c client.c
OBJS     = $(SRCS:.c=.o)
LIBFT   = libft/libft.a
PRINTF	= ft_printf/libftprintf.a




all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) :
	@echo "Compiling libft..."
	@make -C libft
	@echo "libft compiled."

$(PRINTF):
	@echo "Compiling ft_printf..."
	@make -C ft_printf
	@echo "Printf compiled."

$(SERVER) : $(LIBFT) $(PRINTF) $(OBJS)
	@echo "Compiling server..."
	@$(CC) $(FLAGS) -o $(SERVER) server.c $(LIBFT) $(PRINTF)
	@echo "Server compiled."


$(CLIENT) : $(LIBFT) $(PRINTF) $(OBJS)
	@echo "Compiling client..."
	@$(CC) $(FLAGS) -o $(CLIENT) client.c $(LIBFT) $(PRINTF)
	@echo "Client compiled."

clean :
	@make -C libft clean
	@make -C ft_printf clean

fclean : clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re