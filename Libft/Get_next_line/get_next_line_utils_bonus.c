/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:01:49 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/11 16:07:50 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ss;

	if (!s1 || !s2)
		return (NULL);
	ss = malloc((sizeof(char)) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ss)
		return (free(s1), NULL);
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
	return (free(s1), ss);
}
