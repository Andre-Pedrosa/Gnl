/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomas-p <atomas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:14:29 by atomas-p          #+#    #+#             */
/*   Updated: 2025/11/28 18:49:58 by atomas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (*buffer[fd] == 0)
		{
			bytes = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes < 0)
				return (clean_and_check_newline(buffer[fd]), free(line), NULL);
			else if (bytes == 0)
				break ;
			buffer[fd][bytes] = '\0';
		}
		line = ft_strjoin(line, buffer[fd]);
		if (clean_and_check_newline(buffer[fd]))
			break ;
	}
	return (line);
}
/* 
int	main(void)
{
	int		fd_test1;
	int		fd_test2;
	char	*line_test1;
	char	*line_test2;

	fd_test1 = open("test1.txt", O_RDONLY);
	fd_test2 = open("test2.txt", O_RDONLY);
	while (1)
	{
		line_test1 = get_next_line(fd_test1);
		line_test2 = get_next_line(fd_test2);
		if (!line_test1)
		{
			free(line_test1);
			free(line_test2);
			break ;
		}
		printf("%s", line_test1);
		printf("%s", line_test2);
		free(line_test1);
		free(line_test2);
	}
	close(fd_test1);
	close(fd_test2);
	return (0);
}
 */