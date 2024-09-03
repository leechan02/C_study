NAME = $(if $(filter bonus, $(MAKECMDGOALS)), checker, push_swap)
CFLAGS = -g -Wall -Wextra -Werror
SRCS = push_swap.c error.c stacks.c rules.c sort.c min.c max.c merge.c merge_norm.c sort_below_five.c \
	   triangle_make_norm.c triangle_make_re_norm.c triangle.c triangle_check.c triangle_make.c triangle_make_re.c
SRCS_B = checker.c error.c rules.c stacks.c
TO_COMPILE = $(if $(filter bonus, $(MAKECMDGOALS)), $(addprefix Bonus/, $(SRCS_B)), $(addprefix Mandatory/, $(SRCS)))
HEADER = $(if $(filter bonus, $(MAKECMDGOALS)), Bonus/checker.h, Mandatory/push_swap.h)

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(TO_COMPILE) $(HEADER)
	make all -C ft_printf
	cc $(CFLAGS) $(TO_COMPILE) ./ft_printf/libftprintf.a -o $@ 

clean : 
	make clean -C ft_printf

fclean : clean
	make fclean -C ft_printf
	rm -f checker push_swap

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus