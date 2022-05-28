/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:33:14 by vambassa          #+#    #+#             */
/*   Updated: 2021/12/17 11:24:32 by vambassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
