#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf_bonus.h"
#define FORMAT "%05%"
#define DATA 
int	main(int ac, char **av)
{
	int	len;
	int	len2;

	printf("printf :");
	len = printf("%6.s", "abc");
	printf("<");
	printf("\nreturn len : %d\n\n", len);
	//my ft_printf result
	write(1, "ft_printf :", 11);
	len2 = ft_printf("%6.s", "abc");
	printf("<");
	printf("\nreturn ft_len : %d\n", len2);
	return (0);
}
