/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomas-p <atomas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:19:37 by atomas-p          #+#    #+#             */
/*   Updated: 2025/11/28 09:58:33 by atomas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (*buffer == 0)
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes < 0)
				return (clean_and_check_newline(buffer), free(line), NULL);
			else if (bytes == 0)
				break ;
			buffer[bytes] = '\0';
		}
		line = ft_strjoin(line, buffer);
		if (clean_and_check_newline(buffer))
			break ;
	}
	return (line);
}
/* 
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		printf("%s", line);
		free(line);
	}
	return (0);
}
 */