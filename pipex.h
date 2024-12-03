/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:47:58 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/28 14:37:12 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

char	**find_paths(char **envp);
char	*find_path_command(char *command, char **paths);
void	f_clean_all(char **paths, char **command, char *str, int index);
void	error_msg(char *str, int index);
void	close_fdpipe(int index, int fd, int fdpipe[]);
void	execute_child(char **command, char *absolu_path_find, char **envp,
			char **paths);

#endif