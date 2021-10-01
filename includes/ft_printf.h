/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:28:09 by tturner           #+#    #+#             */
/*   Updated: 2021/10/01 12:28:09 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_hold
{
	va_list	arg;
	int		count;
}				t_hold;

int		ft_printf(const char *str, ...);
void	ft_char(t_hold *args);
void	ft_string(t_hold *args);
void	ft_integer(t_hold *args);
void	ft_unsignedint(t_hold *args);
void	ft_hex(t_hold *args, char c);
void	ft_pointer(t_hold *table);

#endif
