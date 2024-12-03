/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:11:04 by cylini            #+#    #+#             */
/*   Updated: 2024/06/05 14:15:16 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destt;
	const unsigned char	*srcc;

	if (src == NULL && dest == NULL)
		return (NULL);
	destt = (unsigned char *) dest;
	srcc = (const unsigned char *) src;
	if (src < dest)
	{
		destt = destt + (n - 1);
		srcc = srcc + (n - 1);
		while (n-- > 0)
		{
			*destt-- = *srcc--;
		}
		return (dest);
	}
	else
	{
		while (n-- > 0)
		{
			*destt++ = *srcc++;
		}
		return (dest);
	}
}
/*
int	main(void)
{
	char	dest[] = {65,66,67,68,69,0,45};

	ft_memmove(dest, dest + 2, 0);
	printf("%s\n", dest);
	return (0);
}*/
