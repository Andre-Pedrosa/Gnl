/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apedrosa <apedrosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:06:53 by apedrosa          #+#    #+#             */
/*   Updated: 2023/02/28 16:35:57 by apedrosa         ###   ########.fr       */
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
// 	int		fd1;
// 	int		fd2;
// 	char	*line;

// 	fd1 = open("txt1.txt", O_RDONLY);
// 	fd2 = open("txt2.txt", O_RDONLY);
// 	line = get_next_line(fd1);
// 	printf("\noutput txt1->%s", line);
// 	line = get_next_line(fd1);
// 	printf("\noutput txt1->%s", line);
// 	line = get_next_line(fd2);
// 	printf("\noutput txt2->%s", line);
// 	line = get_next_line(fd1);
// 	printf("\noutput txt1->%s", line);
// 	line = get_next_line(fd2);
// 	printf("\noutput txt2->%s", line);
// }
