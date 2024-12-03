/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:55 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/11 16:09:00 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*
int	main(void)
{
	int		fd;
	int		count;
	char	*next_line;

	fd = open("newtest.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	count = 0;
	while ((next_line = get_next_line(fd)))
	{
		printf("[%d] : %s", count, next_line);
		free(next_line);
		count++;
	}
	// free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	free(next_line);
	close(fd);
	return (0);
} */

/* int	main(int ac, char **av)
{
	int		fd;
	int		count;
	char	*next_line;

	if (ac != 2)
	{
		printf("Usage: %s <file>\n", av[0]);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	count = 0;
	next_line = get_next_line(fd);
	while (next_line)
	{
		printf("[%d] : %s", count, next_line);
		free(next_line);
		count++;
		next_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
 */
// multiple files
/*int	main(int ac, char **av)
{
	int		fd;
	int		fd2;
	int		count;
	char	*line;
	char	*line2;

	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	line2 = get_next_line(fd2);
	if (ac == 3)
	{
		while (line || line2)
		{
			if (line)
			{
				printf("[%d] : %s", count, line);
				free(line);
				count++;
				line = get_next_line(fd);
			}
			if (line2)
			{
				printf("[%d] : %s", count, line2);
				free(line2);
				count++;
				line2 = get_next_line(fd2);
			}
		}
		close(fd);
		close(fd2);
	}
	else
	{
		printf("Usage: ./a.out file1 file2\n");
		return (1);
	}
	return (0);
}*/
