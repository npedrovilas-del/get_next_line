char *strchr(const char *s, int c)
{
    int l;

    if(!s)
    return(NULL);
    l = 0;
    while(s[l] != c && s[l] != '\0')
    l++;
    return((char *)&s[l]);
}

char *strjoin(char *c, char *f)
{
	int		d;
	int		i;
	char	*new_str;

	if (!c)
	{
		c = malloc(1);
		c[0] = '\0';
	}
	if (!c || !f)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(c) + ft_strlen(f) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (c[++i])
		new_str[i] = c[i];
	d = -1;
	while (f[++d])
	    new_str[i + d] = f[d];
	new_str[i + d] = '\0';
	return (free(c), new_str);
}

static void	*free_all(char **result, char *temp)
{
	free(temp);
	if (result && *result)
	{
		free(*result);
		*result = NULL;
	}
	return (NULL);
}

char *ft_get_line(char *result)
{
    int c;
    char *new_string;

    if(!result)
        return(NULL);
    c = 0;
    new_string = malloc(sizeof(char) * (ft_strlen(result) + 1));
    if(!new_string)
        return(NULL);
    while(result[c] != '\n' && result[c] != '\0')
    {
        new_string[c] = result[c];
        c++;
    }
    if (result[c] == '\n')
	{
		new_string[c] = result[c];
		c++;
	}
    new_string[c] = '\0';
    return(new_string);
}

char *ft_new_result(char *result, char *line)
{
    char *temp; 
    int c;
    int d;

    d = 0;
    c = 0;
    if (!result || !line)
		return (NULL);
    temp = malloc(sizeof (char) * ((ft_strlen(result) - ft_strlen(line)) + 1));
    if(!temp)
    return(NULL);
    while(result[c] == line[c] && result[c] && line[c])
    c++;
    while(result[c] != '\0')
        {
            temp[d] = result[c];
            c++;
            d++;
        }
    temp[d] = '\0';
    free(result);
    return(temp);
}

int ft_strlen(char *str)
{
    int c;

    c = 0;
    if(!str)
    return(0);
    while(str[c] != '\0')
    c++;
    return(c);
}