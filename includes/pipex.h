/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:33:29 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:24:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define STDERR 2

void	child_1_process(int *pipefd, char **argv, char **envp);
void	child_2_process(int *pipefd, char **argv, char **envp);
void	execute_cmd(char *cmd, char **envp);
char	*get_path(char *cmd, char **envp);
char	*strjoin_new(char *str1, char *str2, char joiner);
void	print_error(char *s);
void	print_perror(char *s);
int		str_find_chr(char *s, char c);

#endif
