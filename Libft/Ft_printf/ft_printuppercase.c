/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuppercase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:46:15 by carzhang          #+#    #+#             */
/*   Updated: 2024/06/15 15:25:37 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printuppercase(unsigned int n)
{
	char	*hexadecimal;
	int		i;

	i = 0;
	hexadecimal = "0123456789ABCDEF";
	if (n >= 16)
	{
		i += ft_printuppercase(n / 16);
		i += ft_printuppercase(n % 16);
	}
	else
		i += ft_putchar(hexadecimal[n]);
	return (i);
}
