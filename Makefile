# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 09:46:23 by mbendidi          #+#    #+#              #
#    Updated: 2025/01/17 11:23:50 by mbendidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = gcc 
CFLAGS          = -Wall -Werror -Wextra -g
NAME            = philo
AR              = ar rcs

SRC_PATH        = src/
OBJ_PATH        = obj/

SRC             = main.c \
                init.c \
                thread.c \
                utils.c \
                check.c \
                display.c \
                times.c \
                routine.c \
                death.c

SRCS            = $(addprefix $(SRC_PATH), $(SRC))
OBJ             = $(SRC:.c=.o)
OBJS            = $(addprefix $(OBJ_PATH), $(OBJ))
INC             = -I ./inc/

# Couleurs
GREEN           = \033[1;32m
YELLOW          = \033[1;33m
CYAN            = \033[1;36m
RESET           = \033[0m

all: header $(OBJ_PATH) $(NAME)

header:
	@echo "$(GREEN)"
	@echo "██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗"
	@echo "██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝"
	@echo "██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗"
	@echo "██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║"
	@echo "██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║"
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝"
	@echo "                                  By: Simo                                                  "
	@echo "$(RESET)"

$(OBJ_PATH): 
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread
	@echo "$(GREEN)Compilation complete! ✓$(RESET)"

clean: 
	@rm -rf $(OBJ_PATH)
	@echo "$(GREEN)Cleaned object files ✓$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Cleaned everything ✓$(RESET)"

re: fclean all

norm:
	@norminette ./src/*.c ./inc/*.h

.PHONY: all clean fclean re norm header