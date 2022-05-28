/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:45:30 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:24:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define STDOUT 1
# define STDERR 2

void	many_args_case(int argc, char **argv, char **envp);
void	heredoc_case(int argc, char **argv, char **envp);
void	print_heredoc(char **argv);
void	read_input(int *pipefd, char *lim);
void	redirection(char *cmd, char **envp);
void	execute_cmd(char *cmd, char **envp);
void	print_error(char *s);
void	print_perror(char *s);
char	*get_path(char *cmd, char **envp);
char	*strjoin_new(char *str1, char *str2, char joiner);
int		get_next_line(int fd, char **line);
int		str_find_chr(char *s, char c);

#endif
