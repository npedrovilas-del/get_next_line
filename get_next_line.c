/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pneto-vi <pneto-vi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:59:59 by pneto-vi          #+#    #+#             */
/*   Updated: 2026/05/11 21:29:23 by pneto-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*fill_res(int fd, char *res)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(res, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		res = ft_strjoin(res, buf);
	}
	free(buf);
	return (res);
}

char	*get_line_only(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_substr(stash, 0, i + 1);
	return (line);
}

char	*save_remaining(char *stash)
{
	int		i;
	char	*rest;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = ft_strdup(stash + i + 1);
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = fill_res(fd, res);
	if (!res)
		return (NULL);
	line = get_line_only(res);
	res = save_remaining(res);
	return (line);
}

 int main()
 {
	int fd;
 	char *line;

	fd = open("get_next_line.c" , O_RDONLY);
 		line = get_next_line(fd);
 		printf("%s", line);
		line = get_next_line(fd);
 	    printf("%s", line); 
 		line = get_next_line(fd);
 	    printf("%s", line); 
 	line = get_next_line(fd);
    printf("%s", line);  
        free(line);        
 	close(fd);
}