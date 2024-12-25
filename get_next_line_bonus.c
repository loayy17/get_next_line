/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalhindi <lalhindi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:53:26 by lalhindi          #+#    #+#             */
/*   Updated: 2024/12/25 23:03:22 by lalhindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#define MAX_FD 1024

int	ft_free(char *buffer, char *save)
{
	free(buffer);
	free(save);
	return (1);
}

char	*ft_line(char *remain_str)
{
	int		i;
	char	*line;

	i = 0;
	while (remain_str[i] != '\n' && remain_str[i])
		i++;
	line = malloc(i + 2);
	if (!line)
	{
		free(line);
		return (0);
	}
	i = 0;
	while (remain_str[i] != '\n' && remain_str[i])
	{
		line[i] = remain_str[i];
		i++;
	}
	if (remain_str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *remain_str)
{
	int		i;
	char	*save;
	int		j;

	i = 0;
	while (remain_str[i] != '\n' && remain_str[i])
		i++;
	if (!remain_str[i])
	{
		free(remain_str);
		return (0);
	}
	save = malloc(ft_strlen(remain_str) - i + 1);
	if (!save)
	{
		free(save);
		return (0);
	}
	i++;
	j = 0;
	while (remain_str[i])
		save[j++] = remain_str[i++];
	free(remain_str);
	save[j] = '\0';
	return (save);
}

char	*ft_read_save(int fd, char *save)
{
	char	*buffer;
	ssize_t	reading_byte;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		return (0);
	}
	reading_byte = 1;
	while (!ft_strchr(save, '\n') && reading_byte != 0)
	{
		reading_byte = read(fd, buffer, BUFFER_SIZE);
		if (reading_byte == -1 && ft_free(buffer, save))
			return (0);
		buffer[reading_byte] = '\0';
		save = ft_strjoin(save, buffer);
		if (!save && ft_free(buffer, save))
			return (0);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*remain_str[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
	{
		return (0);
	}
	remain_str[fd] = ft_read_save(fd, remain_str[fd]);
	if (!remain_str[fd])
		return (0);
	line = ft_line(remain_str[fd]);
	remain_str[fd] = ft_save(remain_str[fd]);
	if (!line[0])
	{
		free(line);
		return (0);
	}
	return (line);
}