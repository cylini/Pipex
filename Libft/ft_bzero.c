/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cylini <cylini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:24:45 by cylini            #+#    #+#             */
/*   Updated: 2024/05/26 23:21:46 by cylini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*l;

	l = s;
	while (n > 0)
	{
		*l = 0;
		l++;
		n--;
	}
}
/*
int	main()
{
	char	f[] = "dfghj";
	int	i;
	
	printf("%s\n",f);
	i = 0;
	while (i < 5)
	{
		ft_bzero(f, 4);
		printf("%c", f[i]);
		i++;
	}
	return (0);
}*/
