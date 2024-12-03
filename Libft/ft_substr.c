/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:47:46 by carzhang          #+#    #+#             */
/*   Updated: 2024/05/31 10:25:01 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	news = (char *)malloc(sizeof(char) * (len + 1));
	if (!news)
		return (NULL);
	i = 0;
	while (i < len)
	{
		news[i] = s[start + i];
		i++;
	}
	news[i] = '\0';
	return (news);
}
/*
int     main(void)
{
        char const      s[] = "hello";
        unsigned int    start;
        size_t  len;

        start = 3;
        len = 8;

        printf("%s\n",ft_substr(s, start, len));
        
        return(0);
}*/
