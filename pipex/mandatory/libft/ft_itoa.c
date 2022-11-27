/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nskiba <nskiba@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:43:02 by nskiba            #+#    #+#             */
/*   Updated: 2022/10/13 17:27:11 by nskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long long int nb)
{
	long long int	i;

	i = 1;
	if (nb < 0)
		nb = nb * (-1);
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static long long int	ft_abs(long long int nb)
{
	if (nb < 0)
		nb = nb * (-1);
	return (nb);
}

static char	*ft_putstrnbr(long long int nb, long long int len, char *str)
{
	long long int	i;
	int				isneg;

	isneg = 0;
	if (nb < 0)
		isneg = 1;
	i = len;
	if (nb == 0)
		str[0] = '0';
	nb = ft_abs(nb);
	if (isneg == 0)
		i--;
	while (i >= 0)
	{
		str[i] = (nb % 10 + '0');
		nb = nb / 10;
		i--;
	}
	if (isneg == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*tmp;
	long long int	nx;
	long long int	len;
	int				isneg;

	nx = (long long int)n;
	len = ft_len(nx);
	isneg = 0;
	if (nx < 0)
		isneg = 1;
	tmp = malloc((len + 1 + isneg) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	if (nx == 0)
		tmp[0] = '0';
	tmp = ft_putstrnbr(nx, len, tmp);
	len = len + isneg;
	tmp[len] = '\0';
	return (tmp);
}
