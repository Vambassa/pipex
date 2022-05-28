/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:46:18 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:43:27 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**path_args;
	char	*path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		print_error("Command not found.\n");
	path_args = ft_split(envp[i] + 5, ':');
	if (!path_args || !path_args[0])
		print_error("PATH error.\n");
	i = 0;
	while (path_args[i])
	{
		path = strjoin_new(path_args[i], cmd, '/');
		if (!access(path, F_OK))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
