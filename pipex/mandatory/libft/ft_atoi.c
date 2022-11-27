/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:51:29 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/14 13:04:57 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative(int result, int isneg, int nb)
{
	if (nb > 10 && isneg % 2 != 0)
		return (0);
	if (nb > 10)
		return (-1);
	if (isneg % 2 == 0)
		return (result);
	return (result * -1);
}

static int	ft_whitespace(char c)
{
	if (c == '\n'
		|| c == ' '
		|| c == '\t'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
	{
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	isneg;
	int	j;

	result = 0;
	isneg = 0;
	i = 0;
	j = 0;
	while (ft_whitespace(nptr[i]) == 0)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+' )
	{
		if (nptr[i] == '-')
			isneg++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
		j++;
	}
	return (ft_negative(result, isneg, j));
}
