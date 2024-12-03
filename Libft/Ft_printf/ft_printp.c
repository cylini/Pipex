/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:42:28 by carzhang          #+#    #+#             */
/*   Updated: 2024/06/15 12:39:57 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(void *p)
{
	long unsigned int	addr;
	char				*str;
	int					len;

	addr = (long unsigned int)p;
	if (!p)
		return (ft_putstr("(nil)"));
	str = ft_itoa_base(addr, 16);
	len = 0;
	if (str != NULL)
	{
		write(1, "0x", 2);
		write(1, str, ft_strlen(str));
		len = ft_strlen(str) + 2;
		free(str);
	}
	return (len);
}
