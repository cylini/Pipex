/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_clean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:02:24 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/28 14:37:27 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	execute_child(char **command, char *absolu_path_find, char **envp,
		char **paths)
{
	if (execve(absolu_path_find, command, envp) == -1)
	{
		free(absolu_path_find);
		f_clean_all(paths, command, "execve", -1);
	}
}

void	close_fdpipe(int index, int fd, int fdpipe[])
{
	if (index == 0)
	{
		close(fdpipe[0]);
		close(fdpipe[1]);
	}
	if (index == 1)
	{
		close(fdpipe[0]);
		close(fdpipe[1]);
		close(fd);
	}
}

void	error_msg(char *str, int index)
{
	if (index == 0)
	{
		ft_printf("%s\n", str);
		exit(EXIT_FAILURE);
	}
	if (index == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}

void	f_clean_all(char **paths, char **command, char *str, int index)
{
	int	i;

	if (paths)
	{
		i = -1;
		while (paths[++i])
		{
			free(paths[i]);
			paths[i] = NULL;
		}
		free(paths);
		paths = NULL;
	}
	if (command)
	{
		i = -1;
		while (command[++i])
		{
			free(command[i]);
			command[i] = NULL;
		}
		free(command);
		command = NULL;
	}
	error_msg(str, index);
}
