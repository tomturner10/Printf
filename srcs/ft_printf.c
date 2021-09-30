#include "ft_printf.h"

static void	ft_getflag(const char c, t_hold *args)
{
	if (c == 'c')
		ft_char(args);
	else if (c == 's')
		ft_string(args); 
	else if (c == 'd' || c == 'i')
		ft_integer(args);
	else if (c == 'u')
		ft_unsignedint(args);
	else if (c == 'x' || c == 'X')
		ft_hex(args, c);
	else if (c == 'p')
		ft_ptr(args);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		args->count++;
	}
}

int	ft_printf(const char *str, ...)
{
	t_hold	*args;
	int count;
	int i;

	i = 0;
	count = 0;
	args = (t_hold *)malloc(sizeof(t_hold));
	if (args == NULL)
		return (-1);
	args->count = 0;
	va_start(args->arg, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			args->count++;
		}
		else if (str[i] == '%')
		{
			i++;
			char c = str[i];
			ft_getflag(c, args);
		}
		i++;
	}
	count = args->count;
	va_end(args->arg);
	free(args);
	return count;
}
