// #include "ft_printf.h"

// void ft_lowerhex(t_hold *args)
// {	
// 	int		num;
// 	int		j;
// 	int		rem;
//  	char	hexadecimalnum[100];
	
// 	num = (int)va_arg(args->arg, int);
// 	j = 0;
// 	while (num != 0)
// 	{
// 		rem = num % 16;
// 		if (rem < 10)
// 			hexadecimalnum[j++] = 48 + rem;
// 		else
// 			hexadecimalnum[j++] = 87 + rem;
// 		num = num / 16;
// 	}
// 	args->count += j;
// 	while (j >= 0)
// 	{
// 		j--;
// 		ft_putchar_fd(hexadecimalnum[j], 1);
// 	}
// }

// void ft_upperhex(t_hold *args)
// {	
// 	int		num;
// 	int		j;
// 	int		rem;
//  	char	hexadecimalnum[100];
	
// 	num = va_arg(args->arg, int);
// 	j = 0;
// 	while (num != 0)
// 	{
// 		rem = num % 16;
// 		if (rem < 10)
// 			hexadecimalnum[j++] = 48 + rem;
// 		else
// 			hexadecimalnum[j++] = 55 + rem;
// 		num = num / 16;
// 	}
// 	args->count += j;
// 	while (j >= 0)
// 	{
// 		j--;
// 		ft_putchar_fd(hexadecimalnum[j], 1);
// 	}
// }

// void ft_pointer(t_hold *args)
// {	
// 	unsigned long	num;
// 	int		j;
// 	int		rem;
//  	char	hexadecimalnum[100];
	
// 	num = va_arg(args->arg, unsigned int);
// 	j = 0;
// 	while (num != 0)
// 	{
// 		rem = num % 16;
// 		if (rem < 10)
// 			hexadecimalnum[j++] = 48 + rem;
// 		else
// 			hexadecimalnum[j++] = 87 + rem;
// 		num = num / 16;
// 	}
// 	args->count += j + 2;
// 	ft_putstr_fd("0x", 1);
// 	while (j >= 0)
// 	{
// 		j--;
// 		ft_putchar_fd(hexadecimalnum[j], 1);
// 	}
// }

#include "ft_printf.h"

static char	*ft_ptrstr(unsigned long n, int *k)
{
	char	*str;

	while (n > 15)
	{
		n = n / 16;
		*k += 1;
	}
	str = (char *)malloc(sizeof(char) * (*k + 1));
	if (str == NULL)
		return (NULL);
	str[*k] = '\0';
	return (str);
}

void	ft_hex(t_hold *table, char c)
{
	unsigned int	n;
	int				k;
	char			*str;

	n = va_arg(table->arg, unsigned int);
	k = 1;
	str = ft_ptrstr(n, &k);
	k--;
	while (k >= 0)
	{
		if (n % 16 < 10)
			str[k] = '0' + (n % 16);
		else if (c == 'x')
			str[k] = 'a' + (n % 16) - 10;
		else
			str[k] = 'A' + (n % 16) - 10;
		n = n / 16;
		k--;
		table->count += 1;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ft_ptr(t_hold *table)
{
	unsigned long	n;
	int				k;
	char			*str;

	n = va_arg(table->arg, unsigned long);
	k = 1;
	str = ft_ptrstr(n, &k);
	ft_putstr_fd("0x", 1);
	table->count += 2;
	k--;
	while (k >= 0)
	{
		if (n % 16 < 10)
			str[k] = '0' + (n % 16);
		else
			str[k] = 'a' + (n % 16) - 10;
		n = n / 16;
		k--;
		table->count += 1;
	}
	ft_putstr_fd(str, 1);
	free(str);
}