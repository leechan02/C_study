NAME = fractol
CFLAGS = -O3 -Wall -Wextra -Werror
CLIB = -lmlx -framework OpenGL -framework Appkit
SRCS = fractol.c mandelbrot.c julia.c tricorn.c utils.c color.c

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(addprefix srcs/, $(SRCS)) ./includes/fractol.h
	make all -C libft
	cc $(CFLAGS) $(CLIB) $(addprefix srcs/, $(SRCS)) ./libft/libft.a -o $@ 

clean :
	make clean -C libft

fclean : clean
	make fclean -C libft
	rm -f fractol

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus