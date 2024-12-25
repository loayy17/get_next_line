#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif
int ft_strlen(char *s);
char *ft_strdup(char *s);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char *s1, char *s2);
char *ft_save(char *remain_str);
char *ft_line(char *remain_str);
char *get_next_line(int fd);
#endif