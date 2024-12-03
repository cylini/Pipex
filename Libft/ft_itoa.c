/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:13:04 by carzhang          #+#    #+#             */
/*   Updated: 2024/06/01 15:01:08 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(long int ii)
{
	int	count;

	count = 0;
	if (ii < 0)
	{
		ii *= -1;
		count++;
	}
	if (ii == 0)
		return (1);
	while (ii > 0)
	{
		ii /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	j;
	int			i;

	j = n;
	i = digit_count(n);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = 0;
	if (j == 0)
		str[0] = '0';
	if (j < 0)
	{
		str[0] = '-';
		j = j * -1;
	}
	while (j > 0)
	{
		str[i] = j % 10 + '0';
		i--;
		j = j / 10;
	}
	return (str);
}
