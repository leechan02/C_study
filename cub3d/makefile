NAME = cub3D
CFLAGS = -I $(INCLUDES) -MMD -Wall -Wextra -Werror
LFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS_DIR = ./mandatory/
SRCS_B_DIR = ./bonus/
SRCS = main.c parse.c parse_map.c parse_elements.c run.c hook.c key.c paint.c loop.c free.c setting.c
SRCS_B = main_bonus.c parse_bonus.c parse_map_bonus.c parse_elements_bonus.c run_bonus.c hook_bonus.c key_bonus.c paint_bonus.c loop_bonus.c free_bonus.c minimap_bonus.c setting_bonus.c
SRCS_NAME = $(if $(filter bonus, $(MAKECMDGOALS)), $(addprefix $(SRCS_B_DIR), $(SRCS_B)), $(addprefix $(SRCS_DIR), $(SRCS)))

INCLUDES = ./includes/
SHELL = bash

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_NAME:.c=.o)))

DEPS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_NAME:.c=.d)))

vpath %.c $(SRCS_DIR) $(SRCS_B_DIR)

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	@echo -n "Making game... "
	@make all -s -C libft
	@cc $(OBJS) $(CFLAGS) $(LFLAGS) ./libft/libft.a -o $@ 
	@echo -e "\033[32;1m"complete"\033[0m"
	@sleep 0.2

$(OBJ_DIR) :
	@mkdir $@

$(OBJ_DIR)/%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

clean :
	@echo -n "Deleting object files : "
	@make clean -s -C libft
	@rm -rf $(OBJ_DIR)
	@echo -e "\033[31;1m"delete"\033[0m"
	@sleep 0.2

fclean : clean
	@echo -n "Deleting cub3D : "
	@make fclean -s -C libft
	@rm -f cub3D
	@echo -e "\033[31;1m"delete"\033[0m"
	@sleep 0.2

re : 
	@make fclean
	@make all

.PHONY : all clean fclean re bonus

-include $(DEPS)