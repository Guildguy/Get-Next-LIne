#include "get_next_line.h"

char    *ft_strdup(const char *s)
{
        char    *dup;
        size_t  i;

        i = 0;
        dup = (char *) malloc(ft_strlen(s) + 1);
        if (!dup)
                return (NULL);
        while (s[i])
        {
                dup[i] = s[i];
                i++;
        }
        dup[i] = 0;
        return (dup);
}

size_t  ft_strlen(const char *s)
{
        size_t  length;

        length = 0;
        while (s[length])
        {
                length++;
        }
        return (length);
}