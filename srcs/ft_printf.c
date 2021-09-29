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
	else if (c == 'x')
		ft_lowerhex(args);
	else if (c == 'X')
		ft_upperhex(args);
	else if (c == 'p')
		ft_pointer(args);
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
		else
		{
			i++;
			ft_getflag(str[i], args);
		}
		i++;
	}
	count = args->count;
	va_end(args->arg);
	free(args);
	return count;
}
