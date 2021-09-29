#include "ft_printf.h"

void ft_lowerhex(t_hold *args)
{	
	int		num;
	int		j;
	int		remainder;
 	char	hexadecimalnum[100];
	
	num = (int)va_arg(args->arg, int);
	j = 0;
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 87 + remainder;
		num = num / 16;
	}
	args->count += j;
	while (j >= 0)
	{
		j--;
		ft_putchar_fd(hexadecimalnum[j], 1);
	}
}

void ft_upperhex(t_hold *args)
{	
	int		num;
	int		j;
	int		remainder;
 	char	hexadecimalnum[100];
	
	num = va_arg(args->arg, int);
	j = 0;
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 55 + remainder;
		num = num / 16;
	}
	args->count += j;
	while (j >= 0)
	{
		j--;
		ft_putchar_fd(hexadecimalnum[j], 1);
	}
}

void ft_pointer(t_hold *args)
{	
	unsigned long	num;
	int		j;
	int		remainder;
 	char	hexadecimalnum[100];
	
	num = va_arg(args->arg, unsigned int);
	j = 0;
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 87 + remainder;
		num = num / 16;
	}
	args->count += j + 2;
	ft_putstr_fd("0x", 1);
	while (j >= 0)
	{
		j--;
		ft_putchar_fd(hexadecimalnum[j], 1);
	}
}