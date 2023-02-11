/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apedrosa <apedrosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:06:53 by apedrosa          #+#    #+#             */
/*   Updated: 2023/02/11 19:40:06 by apedrosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd > FOPEN_MAX)
	{
		while (fd > 0 && fd <= FOPEN_MAX && buffer[fd][i])
			buffer[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buffer[fd][0] != '\0' || read(fd, buffer[fd], BUFFER_SIZE))
	{
		line = ft_strjoin(line, buffer[fd]);
		if (clean_buffer(buffer[fd]))
			break ;
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("txt.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("\noutput ->%s", line);
// 	printf("%d", fd);
// }
