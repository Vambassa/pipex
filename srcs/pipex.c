/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:33:09 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:24:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid_1;
	pid_t	pid_2;

	if (argc != 5)
		print_error("Invalid number of arguments.\n");
	if (pipe(pipefd) == -1)
		print_perror("Pipe failed");
	pid_1 = fork();
	if (pid_1 == -1)
		print_perror("Fork failed");
	if (!pid_1)
		child_1_process(pipefd, argv, envp);
	pid_2 = fork();
	if (pid_2 == -1)
		print_perror("Fork failed");
	if (!pid_2)
		child_2_process(pipefd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
	return (0);
}
