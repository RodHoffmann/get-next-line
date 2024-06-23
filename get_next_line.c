/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohoffma <rohoffma@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:23:59 by rohoffma          #+#    #+#             */
/*   Updated: 2024/06/23 14:15:27 by rohoffma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

/*

- Buffer the first Bufer Size bytes
- malloc a new static str with size current plus buffer size
- check for new line or end of file
- if true return new_line including new line char and substr 
- Otherwise malloc current size + size until end of line or null char and set
static ptr to the str after end of line
- 

*/
char	*new_line(char *s);
char	*set_returned_line(char **line, int size, int start, char *s); 
char	*ft_strjoin(char const *s1, char const *s2);
char	*set_buff_and_read(int fd, char **buff, char **line, int *bytes_read);

char	*get_next_line(int fd)
{
	char	*buff;
	static char	*line = "";
	int	bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, buff, BUFFER_SIZE);
	buff[bytes_read] = '\0';
	if (bytes_read == 0 && ft_strlen(line) == 0)
		return (NULL);
	if (new_line(line) && bytes_read < BUFFER_SIZE)
		return (set_returned_line(&line, BUFFER_SIZE, new_line(line) - line + 1, line));
	while (!new_line(buff) && !(bytes_read < BUFFER_SIZE))
		buff = set_buff_and_read(fd, &buff, &line, &bytes_read);
	line = ft_strjoin((char const *)line, (char const *)buff);
	return (set_returned_line(&line, ft_strlen(buff), 0, new_line(line) + 1));
}

char	*new_line(char *s)
{
	char	*new_line_ptr;

	new_line_ptr = ft_strchr((const char *)s, '\n');
	if (new_line_ptr != NULL)
		return (new_line_ptr);
	return (NULL);
}

char	*set_buff_and_read(int fd, char **buff, char **line, int *bytes_read)
{

	*line = ft_strjoin((char const *)*line, (char const *)*buff);
	free(*buff);
	*buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	*bytes_read = read(fd, *buff, BUFFER_SIZE);
	(*buff)[*bytes_read] = '\0';
	return (*buff);
}

char	*set_returned_line(char **line, int size, int start, char *s) 
{
	char	*returned_line;

	returned_line = ft_substr(*line, 0, new_line(*line) - *line);
	*line = ft_substr(s, start, size);
	return (returned_line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	dest_len;
	char	*dest;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest_len = s1_len + s2_len;
	dest = malloc((dest_len + 1) * sizeof(*s1));
	if (dest != NULL)
	{
		ft_strlcpy(dest, s1, s1_len + 1);
		ft_strlcat(dest, s2, dest_len + 1);
	}
	return (dest);
}
