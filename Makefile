# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 13:22:50 by aarbaoui          #+#    #+#              #
#    Updated: 2022/11/27 13:25:06 by aarbaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			=	server
SERVER_SRC		=	server.c
SERVER_OBJ		=	$(SERVER_SRC:.c=.o)

CLIENT			=	client
CLIENT_SRC		=	client.c 
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

UTILS			=	utils
UTILS_SRC		=	utils/ft_atoi.c utils/ft_printf.c utils/ft_putchar.c utils/ft_putmem.c utils/ft_putnbr_b.c utils/ft_putnbr.c utils/ft_putnbr_u.c utils/ft_putstr.c
UTILS_OBJ		=	$(UTILS_SRC:.c=.o)

HEADER			=	minitalk.h

CC				=	cc
FLAGS			= 	-Wall -Werror -Wextra

all : $(UTILS_OBJ) $(SERVER) $(CLIENT)


$(SERVER): $(SERVER_OBJ) $(UTILS_OBJ)
	@$(CC) $(FLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(SERVER)
	@echo "\033[32m$(SERVER) binary created\033[0m"

$(CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
	@$(CC) $(FLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(CLIENT)
	@echo "\033[32m$(CLIENT) binary created\033[0m"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(SERVER_OBJ) $(UTILS_OBJ) $(CLIENT_OBJ)
	@echo "\033[31mObject files deleted\033[0m"

fclean : clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "\033[31m$(SERVER) and $(CLIENT) binaries deleted\033[0m"

re : fclean all