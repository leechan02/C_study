NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_utils.c ft_printf_str.c ft_printf_nbr.c ft_printf_hex.c ft_printf_p.c 
SRCS_B = ft_printf.c ft_printf_utils.c ft_printf_str.c ft_printf_nbr.c ft_printf_hex.c ft_printf_p.c 
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
TO_COMPILE = $(if $(filter bonus, $(MAKECMDGOALS)), $(OBJS_B), $(OBJS))

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(TO_COMPILE)
	make all -C libft
	cp libft/libft.a ./$(NAME)
	ar -rcsu $@ $^

clean :
	make clean -C libft
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
