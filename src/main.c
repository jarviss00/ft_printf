#include "../include/ft_printf.h"

int main(void)
{
	int a = 10;
	int *b = &a;
	ft_printf("%p\n", b);
	ft_printf("%d\n",a);
	printf("%p\n", b);
	return (0);
}