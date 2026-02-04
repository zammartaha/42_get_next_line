/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:47:16 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 18:34:01 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	get_new_line_index(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static	char	*extract_nl(char **rest)
{
	int		idx;
	char	*tmp;
	char	*line;

	if (!*rest)
		return (NULL);
	idx = get_new_line_index(*rest);
	if ((*rest)[idx] == '\n')
	{
		line = substr(*rest, 0, idx + 1);
		tmp = substr(*rest, idx + 1, ft_strlen(*rest));
	}
	else
	{
		line = substr(*rest, 0, idx);
		tmp = NULL;
	}
	if (!line)
	{
		free(*rest);
		return (NULL);
	}
	free(*rest);
	*rest = tmp;
	return (line);
}

static	int	gnl_read_fd(int fd, char **rest)
{
	char		*buf;
	int			bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bytes = 1;
	while ((!*rest || !ft_strchr(*rest, '\n')) && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			free(*rest);
			return (*rest = NULL, -1);
		}
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		*rest = ft_strjoin(*rest, buf);
		if (!*rest)
			return (free(buf), -1);
	}
	return (free(buf), 0);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (gnl_read_fd(fd, &rest) == -1)
		return (NULL);
	return (extract_nl(&rest));
}

// int	main(void)
// {
// 	char	*str;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	return (0);
// }
