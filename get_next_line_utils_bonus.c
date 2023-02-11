/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apedrosa <apedrosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:03:52 by apedrosa          #+#    #+#             */
/*   Updated: 2023/02/11 18:10:07 by apedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*line;

	if (!s1 && !s2)
		return (0);
	line = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!line)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		line[j++] = s1[i++];
	free(s1);
	i = 0;
	while (s2[i])
	{
		line[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	line[j] = '\0';
	return (line);
}

int	clean_buffer(char *buffer)
{
	int	i;
	int	j;
	int	new_line;

	i = 0;
	j = 0;
	new_line = 0;
	while (buffer[i])
	{
		if (new_line == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			new_line = 1;
		buffer[i++] = '\0';
	}
	return (new_line);
}
