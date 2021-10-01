/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:27:24 by tturner           #+#    #+#             */
/*   Updated: 2021/10/01 12:27:24 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strsize(unsigned long num, int *i)
{
	char	*str;

	while (num >= 16)
	{
		num = num / 16;
		*i += 1;
	}
	str = (char *)malloc((*i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[*i] = '\0';
	return (str);
}

void	ft_hex(t_hold *args, char c)
{
	unsigned int	n;
	int				i;
	char			*str;

	n = va_arg(args->arg, unsigned int);
	i = 1;
	str = ft_strsize(n, &i);
	i--;
	while (i >= 0)
	{
		if (n % 16 < 10)
			str[i] = '0' + (n % 16);
		else if (c == 'x')
			str[i] = 'a' - 10 + (n % 16);
		else
			str[i] = 'A' - 10 + (n % 16);
		n = n / 16;
		i--;
		args->count += 1;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ft_pointer(t_hold *args)
{
	unsigned long	n;
	int				i;
	char			*str;

	n = va_arg(args->arg, unsigned long);
	i = 1;
	str = ft_strsize(n, &i);
	ft_putstr_fd("0x", 1);
	args->count += 2;
	i--;
	while (i >= 0)
	{
		if (n % 16 < 10)
			str[i] = '0' + (n % 16);
		else
			str[i] = 'a' - 10 + (n % 16);
		n = n / 16;
		i--;
		args->count += 1;
	}
	ft_putstr_fd(str, 1);
	free(str);
}
