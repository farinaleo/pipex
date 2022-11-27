/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:25:28 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/16 14:11:35 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convertbase(unsigned int n, int maj)
{
	char	c;

	if (maj == 1)
		c = 'A';
	else
		c = 'a';
	if (n >= 16)
	{
		ft_convertbase((n / 16), maj);
		ft_convertbase((n % 16), maj);
	}
	else
	{
		if (n <= 9)
			ft_printchar(n + '0');
		else
			ft_printchar(n - 10 + c);
	}
}

int	ft_printbase(unsigned int n, int maj)
{
	int	len;

	if (n == 0)
	{
		ft_convertbase(n, maj);
		return (1);
	}
	len = ft_ptrlen(n);
	ft_convertbase(n, maj);
	return (len);
}
