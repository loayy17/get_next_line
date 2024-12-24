/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalhindi <lalhindi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 00:15:39 by lalhindi          #+#    #+#             */
/*   Updated: 2024/12/25 00:15:39 by lalhindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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