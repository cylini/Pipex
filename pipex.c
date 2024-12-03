/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:46:58 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/28 14:51:21 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	dup_and_close1(int fd, char *argv, int fdpipe[])
{
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		close_fdpipe(0, 0, fdpipe);
		return (0);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close_fdpipe(1, fd, fdpipe);
		return (0);
	}
	if (dup2(fdpipe[1], STDOUT_FILENO) == -1)
	{
		close_fdpipe(1, fd, fdpipe);
		return (0);
	}
	close_fdpipe(1, fd, fdpipe);
	return (1);
}

int	dup_and_close2(int fd, char *argv, int fdpipe[])
{
	fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		close_fdpipe(0, 0, fdpipe);
		return (0);
	}
	if (dup2(fdpipe[0], STDIN_FILENO) == -1)
	{
		close_fdpipe(1, fd, fdpipe);
		return (0);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close_fdpipe(1, fd, fdpipe);
		return (0);
	}
	close_fdpipe(1, fd, fdpipe);
	return (1);
}

void	child1(char *argv[], char **paths, char **envp, int fdpipe[])
{
	int		fd;
	pid_t	pid;
	char	**command1;
	char	*absolu_path_find;

	fd = 0;
	command1 = ft_split(argv[2], ' ');
	absolu_path_find = find_path_command(command1[0], paths);
	pid = fork();
	if (pid == -1)
		f_clean_all(paths, command1, "fork", -1);
	else if (pid == 0)
	{
		if (!absolu_path_find)
			f_clean_all(paths, command1, "Command not found", 0);
		if (dup_and_close1(fd, argv[1], fdpipe) == 0)
		{
			free(absolu_path_find);
			f_clean_all(paths, command1, "File descriptor", -1);
		}
		execute_child(command1, absolu_path_find, envp, paths);
	}
	f_clean_all(NULL, command1, NULL, 1);
	free(absolu_path_find);
}

void	child2(char *argv[], char **paths, char **envp, int fdpipe[])
{
	int		fd;
	pid_t	pid;
	char	**command2;
	char	*absolu_path_find;

	fd = 0;
	command2 = ft_split(argv[3], ' ');
	absolu_path_find = find_path_command(command2[0], paths);
	pid = fork();
	if (pid == -1)
		f_clean_all(paths, command2, "fork", -1);
	else if (pid == 0)
	{
		if (!absolu_path_find)
			f_clean_all(paths, command2, "Command not found", 0);
		if (dup_and_close2(fd, argv[4], fdpipe) == 0)
		{
			free(absolu_path_find);
			f_clean_all(paths, command2, "File descriptor", -1);
		}
		execute_child(command2, absolu_path_find, envp, paths);
	}
	f_clean_all(NULL, command2, NULL, 1);
	free(absolu_path_find);
}

int	main(int argc, char *argv[], char **envp)
{
	int		i;
	int		fdpipe[2];
	char	**paths;

	if (argc != 5)
	{
		ft_printf("Need this format: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	paths = find_paths(envp);
	pipe(fdpipe);
	child1(argv, paths, envp, fdpipe);
	child2(argv, paths, envp, fdpipe);
	close(fdpipe[0]);
	close(fdpipe[1]);
	i = 0;
	while (i < 2)
	{
		wait(NULL);
		i++;
	}
	f_clean_all(paths, NULL, NULL, 1);
	return (0);
}
