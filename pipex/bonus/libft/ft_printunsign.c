/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:52:52 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/12 16:25:30 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unsignlen(long long int n)
{
	int	len;

	len = 0;
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

static void	ft_putunsign_fd(unsigned int n, int fd)
{
	long long int	nx;

	nx = (unsigned int)n;
	if (nx > 9)
	{
		ft_putunsign_fd(nx / 10, fd);
		ft_printchar(nx % 10 + '0');
	}
	else
	{
		ft_printchar(nx + '0');
	}
}

int	ft_printunsign(unsigned int n)
{
	int	len;

	len = 0;
	len += ft_unsignlen(n);
	ft_putunsign_fd(n, 1);
	return (len);
}
