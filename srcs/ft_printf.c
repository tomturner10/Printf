/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:27:24 by tturner           #+#    #+#             */
/*   Updated: 2021/10/01 12:27:24 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_pointer(args);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		args->count++;
	}
}

static t_hold	*ft_initargs(void)
{
	t_hold	*args;

	args = (t_hold *)malloc(sizeof(t_hold));
	if (args == NULL)
		return (NULL);
	args->count = 0;
	return (args);
}

int	ft_printf(const char *str, ...)
{
	t_hold	*args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	args = ft_initargs();
	va_start(args->arg, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			args->count++;
		}
		else if (str[i] == '%')
			ft_getflag(str[++i], args);
		i++;
	}
	count = args->count;
	va_end(args->arg);
	free(args);
	return (count);
}
