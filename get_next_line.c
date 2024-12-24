/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalhindi <lalhindi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:53:26 by lalhindi          #+#    #+#             */
/*   Updated: 2024/12/22 21:53:26 by lalhindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *get_line(char **remain_str)
{
    char *newline_position;
    char *line;
    char *temp;

    newline_position = ft_strchr(*remain_str, '\n');
    if (newline_position)
    {
        line = ft_strdup(*remain_str);
        line[newline_position - *remain_str] = '\0';
        temp = ft_strdup(newline_position + 1);
        free(*remain_str);
        *remain_str = temp;
    }
    else
    {
        line = ft_strdup(*remain_str);
        free(*remain_str);
        *remain_str = NULL;
    }
    return line;
}
char *get_next_line(int fd)
{
    static char *remain_str;
    char buffer[BUFFER_SIZE + 1];
    ssize_t reading_byte;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    if (!remain_str)
        remain_str = ft_strdup("");
    while (!ft_strchr(remain_str, '\n'))
    {
        reading_byte = read(fd, buffer, BUFFER_SIZE);
        if (reading_byte <= 0)
            break;
        buffer[reading_byte] = '\0';
        remain_str = ft_strjoin(remain_str, buffer);
    }
    if (!remain_str || !*remain_str)
        return NULL;
    return get_line(&remain_str);
}

int main()
{
	int fd;
	fd = open("example.txt",O_RDONLY);
	// printf("line = %s\n",ft_strjoin("hello"," world"));
	while(get_next_line(fd))
	{
		printf("line = %s\n",get_next_line(fd));
	}
	// printf("line = %s\n",get_next_line(fd));
	// printf("line = %s\n",get_next_line(fd));
	// printf("line = %s\n",get_next_line(fd));
	// printf("line = %s\n",get_next_line(fd));
	// printf("line = %s\n",get_next_line(fd));
	// printf("line = %s\n",get_next_line(fd));
	// printf("line = %s\n",get_next_line(fd));
	// printf("line = %s\n",get_next_line(fd));
	// printf("line = %s\n",get_next_line(fd));
	return 0;
}