/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:32:46 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:24:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_1_process(int *pipefd, char **argv, char **envp)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY);
	if (fdin < 0)
		print_perror(argv[1]);
	if (dup2(fdin, STDIN_FILENO) == -1)
		print_perror("Dup2 failed");
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		print_perror("Dup2 failed");
	close(pipefd[0]);
	close(pipefd[1]);
	close(fdin);
	execute_cmd(argv[2], envp);
}

void	child_2_process(int *pipefd, char **argv, char **envp)
{
	int	fdout;

	fdout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdout < 0)
		print_perror(argv[4]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		print_perror("Dup2 failed");
	if (dup2(fdout, STDOUT_FILENO) == -1)
		print_perror("Dup2 failed");
	close(pipefd[1]);
	close(pipefd[0]);
	close(fdout);
	execute_cmd(argv[3], envp);
}
