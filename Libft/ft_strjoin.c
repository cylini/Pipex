/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:45:58 by carzhang          #+#    #+#             */
/*   Updated: 2024/05/31 11:57:12 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*ss;

	if (!s1 || !s2)
		return (NULL);
	ss = malloc((sizeof(char)) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ss)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ss[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ss[i] = s2[j];
		i++;
		j++;
	}
	ss[i] = '\0';
	return (ss);
}
/*
int	main(void)
{
	const char	s1[] = "Bonjour";
	const char	s2[] = "Hello";

	printf("%s\n",ft_strjoin(s1,s2));
	return (0);
}*/
