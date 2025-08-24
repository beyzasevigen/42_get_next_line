#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


char *read_line(char *str_all, int fd)
{
    char *buffer;
    int bytes;

    bytes = 0;
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
    {
        perror("bellek ayrilamadi");
        return (NULL);
    }
    while((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes] = '\0';
        printf("okunan satır: %s\n",buffer);
    }
    return (buffer);
}


int main()
{
    
    static char *new_str;
    
    int fd = open("dosya.txt", O_RDONLY);
    if(fd < 0)
    {
        perror("dosya acilamadi");
        return 1;
    }

    
    

    
    
    if(bytes < 0)
    {
        perror("okuma hatasi");
    }

    free(buffer);
    close(fd);
    return 0;
}