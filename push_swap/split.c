
static char    *ft_strncpy(char *dest, char *src, int n)
{
    int i = 0;    while (i < n && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

static int ft_wordcount(char *str)
{    
    
    int wordcount = 0;
    int i = 0;    
    
    while (str[i])
    {
        while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == 10))
            i++;
        if (str[i])
            wordcount++;
        while (str[i] && (str[i] != 32 && str[i] != 9 && str[i] != 10))
            i++;
    }
    return (wordcount);
}

char    **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;    
        
    char **res = (char **)malloc(sizeof(char *) * (ft_wordcount(str) + 1));
    
    while (str[i])
    {
        while (str[i] && (str[i] == 32))
            i++;
        j = i;
        while (str[i] && (str[i] != 32))
            i++;
        if (i > j)
        {
            res[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
            ft_strncpy(res[k++], &str[j], i - j);
        }
    }
    res[k] = '\0';
    return (res);
}