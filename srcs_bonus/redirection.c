/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:46:34 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:24:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	redirection(char *cmd, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		print_perror("Pipe failed");
	pid = fork();
	if (pid == -1)
		print_perror("Fork failed");
	if (!pid)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			print_perror("Dup2 failed");
		close(pipefd[1]);
		execute_cmd(cmd, envp);
	}
	else
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			print_perror("Dup2 failed");
		close(pipefd[0]);
		waitpid(pid, NULL, 0);
	}
}
