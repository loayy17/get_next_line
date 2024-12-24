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
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

			
int ft_strlen(char *s)
{
    int i;

	i = 0;
    while (s[i])
        i++;
    return i;
}

char *ft_strdup(char *s)
{
    char *str;
    int i = 0;
    
	i = 0;
    if (!s)
        return NULL;
    str = malloc(ft_strlen(s) + 1);
    if (!str)
        return NULL;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
char *ft_strchr(const char *s, int c)
{
    if (!s)
        return NULL;
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return NULL;
}
char *ft_strjoin(char *s1, char *s2)
{
	char *result;
	int i;
	int j;

	i=0;
	j=0;
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 );
	if(!result)
	return NULL;
	while(s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		result[i+j] = s2[j];
		j++;
	}
	result[i+j] = '\0';
	return result;
}
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
	printf("line = %s\n",get_next_line(fd));
	printf("line = %s\n",get_next_line(fd));
	printf("line = %s\n",get_next_line(fd));
	printf("line = %s\n",get_next_line(fd));
	printf("line = %s\n",get_next_line(fd));
	printf("line = %s\n",get_next_line(fd));
	printf("line = %s\n",get_next_line(fd));
	printf("line = %s\n",get_next_line(fd));
	return 0;
}