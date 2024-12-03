/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cylini <cylini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:05:28 by carzhang          #+#    #+#             */
/*   Updated: 2024/05/28 15:44:39 by cylini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	ptr = s;
	i = 0;
	while (s[i])
	{
		i++;
	}
	while (&s[i] != ptr - 1)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i--;
	}
	if (c == '\0')
		return ((char *)ptr);
	return (0);
}
/*
int	main()
{
	const char	s[] = "tripouille";
	char	c = 'l';
	char	*br;

	printf("chaine original '%s'\n",s);

	br = ft_strrchr(s, 'l');
	printf("la derniere occurrence avec '%c' dans '%s' : %s", c, s, br);
	return (0);
}*/
