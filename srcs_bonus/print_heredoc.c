/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:46:31 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:24:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	read_input(int *pipefd, char *lim)
{
	char	*line;

	write(STDOUT, "pipe heredoc> ", 14);
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(lim, line))
		{
			close(pipefd[1]);
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (write(pipefd[1], line, ft_strlen(line)) == -1)
			print_perror("Write error");
		if (write(pipefd[1], "\n", 1) == -1)
			print_perror("Write error");
		write(STDOUT, "pipe heredoc> ", 14);
		free(line);
	}
	close(pipefd[1]);
	free(line);
	print_error("Didn't find the LIMITER.\n");
}

void	print_heredoc(char **argv)
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
		read_input(pipefd, argv[2]);
	}
	else
	{
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			print_perror("Dup2 failed");
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pid, NULL, 0);
	}
}
