/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:08:06 by cylini            #+#    #+#             */
/*   Updated: 2024/06/05 14:25:23 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
/*
int	main()
{
	const char	s[] = "ciarine";
	char	c = 'i';
	char	*br;

	printf("chaine original '%s'\n",s);

	br = ft_strchr(s, 'i');
	printf("la premiere occurrence avec '%c' dans '%s' : %s", c, s, br);
	return (0);
}*/
