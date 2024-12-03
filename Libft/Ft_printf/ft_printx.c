/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:03:18 by carzhang          #+#    #+#             */
/*   Updated: 2024/06/15 15:14:33 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(unsigned int n)
{
	char	*hexadecimal;
	int		i;

	i = 0;
	hexadecimal = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_printx(n / 16);
		i += ft_printx(n % 16);
	}
	else
		i += ft_putchar(hexadecimal[n]);
	return (i);
}
