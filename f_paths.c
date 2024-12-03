/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_paths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:56:31 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/28 14:36:01 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_paths(char **envp)
{
	int		i;
	char	*str;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			str = envp[i] + 5;
			paths = ft_split(str, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

char	*find_path_command(char *command, char **paths)
{
	int		j;
	char	*part1;
	char	*part2;
	char	*absolu_path;

	j = 0;
	absolu_path = NULL;
	if (access(&command[0], F_OK | X_OK) == 0)
		return (ft_strdup(&command[0]));
	if (!paths)
		return (NULL);
	while (paths[j])
	{
		part1 = ft_strjoin(paths[j], "/");
		part2 = ft_strjoin(part1, &command[0]);
		free(part1);
		if (access(part2, F_OK | X_OK) == 0)
		{
			absolu_path = part2;
			break ;
		}
		free(part2);
		j++;
	}
	return (absolu_path);
}
