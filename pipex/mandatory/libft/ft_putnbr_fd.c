/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:51:19 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/11 23:45:09 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nx;

	nx = (long long int)n;
	if (nx < 0)
	{
		ft_putchar_fd('-', fd);
		nx = -nx;
	}
	if (nx > 9)
	{
		ft_putnbr_fd(nx / 10, fd);
		ft_putchar_fd(nx % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(nx + '0', fd);
	}
}
