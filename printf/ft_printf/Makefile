NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_utils.c ft_printf_str.c ft_printf_nbr.c ft_printf_hex.c ft_printf_p.c 
SRCS_B = ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_str_bonus.c ft_printf_nbr_bonus.c ft_printf_hex_bonus.c ft_printf_p_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
HEADER = $(if $(filter bonus, $(MAKECMDGOALS)), ft_printf.h, ft_printf.h)
TO_COMPILE = $(if $(filter bonus, $(MAKECMDGOALS)), $(OBJS_B), $(OBJS))

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(TO_COMPILE) $(HEADER)
	rm -f $(NAME)
	ar -rcsu $@ $^

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
