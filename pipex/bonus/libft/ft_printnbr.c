/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:03:27 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/12 16:45:12 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	if (n < 10)
	{
		len++;
		return (len);
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_printnbr(int n)
{
	int	len;

	len = 0;
	len += ft_nbrlen(n);
	ft_putnbr(n);
	return (len);
}
