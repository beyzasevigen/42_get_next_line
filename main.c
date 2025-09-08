#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <get_next_line.h>

//char *get_next_line(int fd);

int main(void)
{
    int fd;
    char *line;

    fd = open("dosya.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }
/*     line = get_next_line(fd);
    printf("LINE: %s", line);
    free(line);
    line = get_next_line(fd);
    printf("LINE: %s", line);
    free(line);
    line = get_next_line(fd);
    printf("LINE: %s", line);
    free(line);
    line = get_next_line(fd);
    printf("LINE: %s", line);
    free(line);
    line = get_next_line(fd);
    printf("LINE: %s", line);
    free(line);
    line = get_next_line(fd);
    printf("LINE: %s", line);
    free(line);
    line = get_next_line(fd);
    printf("LINE: %s", line);
    free(line); */
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }

    close(fd);
    return (0);
}