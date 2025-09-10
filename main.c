#include <fcntl.h>
#include "get_next_line.h"
# include <stdio.h>

int main()
{
    int fd = open("dosya.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
}