#include "ft_printf.h"

void	ft_printf(const char* fmt, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;
	int		integer;
	int		character;
	double	decimal;

	i = 0;
	va_start(args, fmt);
	len = strlen(fmt);
	while (fmt[i] != '\0' || i < len)
	{
		if (fmt[i] == 'd')
		{
			integer = va_arg(args, int);
			printf("%d\n", integer);
		}
		else if (fmt[i] == 'c')
		{
			character = va_arg(args, int);
			printf("%c\n", character);
		}
		else if (fmt[i] == 'f')
		{
			decimal = va_arg(args, double);
			printf("%f\n", decimal);
		}
		i++;
	}
	va_end(args);
}

int main()
{
	ft_printf("dc", 10, 'a');
	return (0);
}