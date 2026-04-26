#include <unistd.h>

char *get_next_line(int fd)
{
    int n;
    char    *temp;
    static char *result;
    char *line;

    n = 1;
    if(BUFFER_SIZE <= 0)
    {
        return(NULL);
    }
    temp = malloc(sizeof(char) *(BUFFER_SIZE + 1));
    while(!ft_strchr(result, '\n') && n != '\0')
    {
        n = read(fd,temp,BUFFER_SIZE);
        if(n == -1)
        {
            return(free_all(&result, temp));
        }
        temp[n] = '\0';
        result = ft_strjoin(result, temp);
    }
    free(temp);
    line = ft_get_line(result);
    result = ft_new_result(result,line);
    return(line);
}