NAME = philo
CFLAGS = -I $(INCLUDES) -Wall -Wextra -Werror

SRCS_DIR = ./srcs/
SRCS = main.c utils.c philosopher.c philosophy_club.c
SRCS_NAME = $(addprefix $(SRCS_DIR), $(SRCS))

INCLUDES = ./includes/
SHELL = bash

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_NAME:.c=.o)))

vpath %.c $(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS) $(INCLUDES)
	@echo -n "Philosophers sitting on a table... "
	@cc $(OBJS) -o $@ 
	@echo -e "\033[32;1m"complete"\033[0m"
	@sleep 0.2

$(OBJ_DIR) :
	@mkdir $@

$(OBJ_DIR)/%.o : %.c $(OBJ_DIR)
	@cc $(CFLAGS) -c $< -o $@

clean :
	@echo -n "Deleting object files : "
	@rm -rf $(OBJ_DIR)
	@echo -e "\033[31;1m"delete"\033[0m"
	@sleep 0.2

fclean : clean
	@echo -n "Party is over : "
	@rm -f philo
	@echo -e "\033[31;1m"delete"\033[0m"
	@sleep 0.2

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re