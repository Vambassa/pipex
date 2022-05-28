/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:32:56 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:45:51 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute_cmd(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*path;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args || !cmd_args[0])
		print_error("Command error.\n");
	if (str_find_chr(cmd_args[0], '/') > -1)
		path = cmd_args[0];
	else
		path = get_path(cmd_args[0], envp);
	if (!path)
		print_error("Command not found.\n");
	if (execve(path, cmd_args, envp) == -1)
		print_perror("Execution error");
}
