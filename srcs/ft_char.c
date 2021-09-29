#include "ft_printf.h"

void	ft_char(t_hold *args)
{
	ft_putchar_fd(va_arg(args->arg, int) , 1);
	args->count++;
}

void	ft_string(t_hold *args)
{
	int	len;
	char *str;

	str = va_arg(args->arg, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		args->count += 6;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		args->count += len;
	}
}