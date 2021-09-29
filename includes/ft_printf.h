#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_hold
{
	va_list	arg;
	int	count;
}				t_hold;

int		ft_printf(const char *str, ...);
void	ft_char(t_hold *args);
void	ft_string(t_hold *args);
void	ft_integer(t_hold *args);
void	ft_unsignedint(t_hold *args);
void	ft_lowerhex(t_hold *args);
void	ft_upperhex(t_hold *args);
void	ft_pointer(t_hold *args);

#endif
