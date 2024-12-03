/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:00:08 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/16 12:14:15 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *str)
{
	ssize_t	r;
	char	*buf;

	r = 1;
	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(str), NULL);
	while (!ft_strchr(str, '\n') && r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			return (free(str), free(buf), NULL);
		}
		buf[r] = '\0';
		str = ft_strjoin_free_s1(str, buf);
		if (!str)
			break ;
	}
	free(buf);
	return (str);
}

static char	*get_the_line(char *str, char *line)
{
	int	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc((i + 1 + (str[i] == '\n')) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*del_cre(char *str)
{
	ssize_t	len;
	ssize_t	l;
	char	*cre;

	len = 0;
	if (!str)
		return (free(str), NULL);
	while (str[len] != '\n' && str[len])
		len++;
	if (!str[len])
		return (free(str), NULL);
	cre = malloc((ft_strlen(str) - len + 1) * sizeof(char));
	if (!cre)
		return (free(str), NULL);
	len++;
	l = 0;
	while (str[len])
		cre[l++] = str[len++];
	cre[l] = '\0';
	free(str);
	return (cre);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(str), str = NULL, NULL);
	str = read_line(fd, str);
	if (!str)
		return (free(str), str = NULL, NULL);
	line = NULL;
	line = get_the_line(str, line);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = del_cre(str);
	free(str);
	str = NULL;
	return (line);
}
