/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:59:46 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/12 16:24:12 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_ptr(unsigned long long n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_printchar(n + '0');
		else
			ft_printchar(n - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long n)
{
	int	len;

	len = 0;
	if (n != 0)
		len += write(1, "0x", 2);
	if (n == 0)
		len += write(1, "(nil)", 5);
	else
	{
		ft_put_ptr(n);
	}
	len += ft_ptrlen(n);
	return (len);
}
