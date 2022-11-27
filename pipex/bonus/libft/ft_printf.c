/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:28:38 by nskiba            #+#    #+#             */
/*   Updated: 2022/11/02 14:02:41 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list args, const char c)
{
	int	j;

	j = 0;
	if (c == 'c')
		j += ft_printchar(va_arg(args, int));
	else if (c == 's')
		j += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		j += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		j += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		j += ft_printunsign(va_arg(args, unsigned int));
	else if (c == 'x')
		j += ft_printbase(((unsigned int)va_arg(args, int)), 0);
	else if (c == 'X')
		j += ft_printbase(((unsigned int)va_arg(args, int)), 1);
	else if (c == '%')
		j += ft_printchar('%');
	else
	{
		j += ft_printchar('%');
		j += ft_printchar(c);
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			j;

	i = 0;
	j = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			j += ft_format(args, str[i + 1]);
			i++;
		}
		else
			j += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (j);
}
