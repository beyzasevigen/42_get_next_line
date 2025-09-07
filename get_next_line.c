/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsevigen <bsevigen@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:53:24 by bsevigen          #+#    #+#             */
/*   Updated: 2025/08/24 16:14:25 by bsevigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd, char *str) 
{ 
    char *buffer; 
    int bytes; 

    if (!str)
    {
        printf("[DEBUG] str is NULL, initializing\n");
        str = ft_strdup("");
    }
    buffer = malloc(BUFFER_SIZE + 1); 
    if(!buffer) return (NULL); 
    bytes = 1; 
    while(bytes > 0 && !ft_strchr(str, '\n')) 
    { 
        bytes = read(fd, buffer, BUFFER_SIZE); 
        /* if(bytes < 0) 
        { 
            free(buffer); 
            return (NULL); 
        }  */
       if (bytes == 0) // EOF
        {
            free(buffer);
            if (str && *str) // eğer kalan veri varsa döndür
                return str;
            free(str);
            return NULL; // artık okunacak satır kalmadı
        }
        buffer[bytes] = '\0'; 
        str = ft_strjoin(str, buffer);   
    } 
    printf("[DEBUG] str so far: '%s'\n", str);
    free(buffer); 
    return (str); 
}
char *get_remain_line(char *str)
{
    char *newline;
    char *remain;

    if (!str)
        return (NULL);

    newline = ft_strchr(str, '\n');
    if (!newline)
    {
        free(str);
        return (NULL);
    }

    remain = ft_strdup(newline + 1);
    free(str);
    return (remain);
}
char *get_single_line(char *str)
{
    char *line;
    int count;

    count = 0;
    if (!str)
        return (NULL);
    while(str[count] != '\n' && str[count] != '\0')
    {
        count++;
    }
    line = ft_substr_new(str, 0, count);
    return (line);
}
char *get_next_line(int fd)
{
    static char *str;
    char *line;
    char *temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = read_line(fd, str);
    if (!str)
        return (NULL);
    line = get_single_line(str);
    if (!line)
        return (NULL);
    str = get_remain_line(str);
    return (line);
}
