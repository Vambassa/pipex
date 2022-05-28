/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:46:23 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:24:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	heredoc_case(int argc, char **argv, char **envp)
{
	int	i;
	int	fdout;

	if (argc < 6)
		print_error("invalid number of arguments.\n");
	print_heredoc(argv);
	fdout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fdout < 0)
		print_perror(argv[argc - 1]);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		print_perror("Dup2 failed");
	i = 3;
	while (i < argc - 2)
	{
		redirection(argv[i], envp);
		i++;
	}
	execute_cmd(argv[argc - 2], envp);
	return ;
}

void	many_args_case(int argc, char **argv, char **envp)
{
	int	i;
	int	fdin;
	int	fdout;

	if (argc < 5)
		print_error("Invalid number of arguments.\n");
	fdin = open(argv[1], O_RDONLY);
	if (fdin < 0)
		print_perror(argv[1]);
	if (dup2(fdin, STDIN_FILENO) == -1)
		print_perror("Dup2 failed");
	fdout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdout < 0)
		print_perror(argv[argc - 1]);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		print_perror("Dup2 failed");
	i = 2;
	while (i < argc - 2)
	{
		redirection(argv[i], envp);
		i++;
	}
	execute_cmd(argv[argc - 2], envp);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	if (!ft_strcmp(argv[1], "here_doc"))
		heredoc_case(argc, argv, envp);
	else
		many_args_case(argc, argv, envp);
	return (0);
}
