/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:24:00 by carzhang          #+#    #+#             */
/*   Updated: 2024/09/08 12:15:26 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	varconversions(va_list arg, const char type)
{
	if (type == 'c')
		return (ft_putchar((va_arg(arg, int))));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_printd(va_arg(arg, int)));
	else if (type == 'u')
		return (ft_print_unsigned(va_arg(arg, unsigned int)));
	else if (type == 'p')
		return (ft_printp(va_arg(arg, void *)));
	else if (type == 'x')
		return (ft_printx(va_arg(arg, int)));
	else if (type == 'X')
		return (ft_printuppercase(va_arg(arg, int)));
	else if (type == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, str);
	len = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i] != 0)
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			len = len + varconversions(arg, str[i + 1]);
			i += 1;
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
