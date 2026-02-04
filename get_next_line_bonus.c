/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:47:16 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 18:33:56 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static	char	*extract_nl(int fd, char **rest)
{
	int		idx;
	char	*tmp;
	char	*line;

	if (!rest[fd])
		return (NULL);
	idx = get_new_line_index(rest[fd]);
	if ((rest[fd])[idx] == '\n')
	{
		line = substr(rest[fd], 0, idx + 1);
		tmp = substr(rest[fd], idx + 1, ft_strlen(rest[fd]));
	}
	else
	{
		line = substr(rest[fd], 0, idx);
		tmp = NULL;
	}
	if (!line)
	{
		free(rest[fd]);
		return (NULL);
	}
	free(rest[fd]);
	rest[fd] = tmp;
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
	while ((!rest[fd] || !ft_strchr(rest[fd], '\n')) && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (rest[fd] = NULL, -1);
		}
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		rest[fd] = ft_strjoin(rest[fd], buf);
		if (!rest[fd])
			return (free(buf), -1);
	}
	return (free(buf), 0);
}

char	*get_next_line(int fd)
{
	static char	*rest[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (gnl_read_fd(fd, rest) == -1)
		return (NULL);
	return (extract_nl(fd, rest));
}
