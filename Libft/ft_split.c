/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:27:34 by carzhang          #+#    #+#             */
/*   Updated: 2024/06/05 17:11:37 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

static int	countw(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	ft_free(char **a, int k)
{
	while (k > 0)
		free(a[--k]);
	free(a);
}

static size_t	get_len_until_char( const char *s, char c)
{
	const char	*next;

	next = ft_strchr(s, c);
	if (next)
		return ((size_t)(next - s));
	else
		return (ft_strlen(s));
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	size_t	len;
	int		k;

	a = (char **)malloc(sizeof(char *) * (countw(s, c) + 1));
	if (!a)
		return (NULL);
	k = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = get_len_until_char(s, c);
			a[k] = ft_substr(s, 0, len);
			if (!a[k++])
				return (ft_free(a, k - 1), NULL);
			s = s + len;
		}
	}
	a[k] = NULL;
	return (a);
}
