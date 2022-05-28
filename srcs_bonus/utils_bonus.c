/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:46:38 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:24:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	str_find_chr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (-1);
}

void	print_perror(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	print_error(char *s)
{
	write(STDERR, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}

char	*strjoin_new(char *str1, char *str2, char joiner)
{
	char	*s;
	int		i;
	int		j;

	if (!str1 || !str2)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 2));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		s[i] = str1[i];
		i++;
	}
	s[i++] = joiner;
	while (str2[j])
		s[i++] = str2[j++];
	s[i] = '\0';
	return (s);
}

int	get_next_line(int fd, char **line)
{
	int		rd;
	int		i;
	char	*buffer;

	i = 0;
	buffer = (char *)malloc(100000);
	*line = buffer;
	rd = read(fd, &buffer[i], 1);
	while (rd > 0 && buffer[i] != '\n')
	{
		i++;
		rd = read(fd, &buffer[i], 1);
	}
	buffer[i] = '\0';
	return (rd);
}
