/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cylini <cylini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:07:33 by cylini            #+#    #+#             */
/*   Updated: 2024/05/28 15:53:53 by cylini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (char) c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	block[20];

	ft_memset(block, 'B', sizeof(block));
	int	i;
	
	i = 0;
	while (i < 20)
	{
		printf("%c", block[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
