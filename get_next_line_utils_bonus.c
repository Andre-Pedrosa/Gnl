/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomas-p <atomas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:22:07 by atomas-p          #+#    #+#             */
/*   Updated: 2025/11/28 10:17:46 by atomas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	clean_and_check_newline(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	nl;

	i = 0;
	j = 0;
	nl = 0;
	while (buffer[i])
	{
		if (nl == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			nl = 1;
		buffer[i++] = '\0';
	}
	return (nl);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;
	size_t			i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*line;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	line = malloc(s1_len + s2_len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, s1, s1_len);
	ft_memcpy(line + s1_len, s2, s2_len);
	line[s1_len + s2_len] = '\0';
	free (s1);
	return (line);
}
