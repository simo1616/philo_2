
CC 				= gcc 
CFLAGS 			= -Wall -Werror -Wextra -g
NAME 			= philo
AR				= ar rcs

SRC_PATH 		= src/
OBJ_PATH 		= obj/

SRC 			= main.c \
				init.c \
				thread.c \
				utils.c \
				check.c \
				display.c \
				times.c

SRCS 			= $(addprefix $(SRC_PATH), $(SRC))
OBJ 			= $(SRC:.c=.o)
OBJS 			= $(addprefix $(OBJ_PATH), $(OBJ))
INC 			= -I ./inc/


all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH): 
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread
	@echo -n "\033[033mcompile terminate\033[0m\n"

clean: 
	rm -rf $(OBJ_PATH)
fclean: clean
	rm -f $(NAME)
	@echo -n "\033[093mall clean\033[0m\n"

re: fclean all

norm:
	@norminette $(SRC) ./inc/*.h

.PHONY: all clean fclean re	norm
