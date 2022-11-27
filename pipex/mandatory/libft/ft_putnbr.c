/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:45:19 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/12 16:45:31 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long int	nx;

	nx = (long long int)n;
	if (nx < 0)
	{
		ft_putchar('-');
		nx = -nx;
	}
	if (nx > 9)
	{
		ft_putnbr(nx / 10);
		ft_putchar(nx % 10 + '0');
	}
	else
	{
		ft_putchar(nx + '0');
	}
}
