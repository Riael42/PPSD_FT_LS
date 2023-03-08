#include "FT_LS.h"

char*   ft_strcat_c(char* dest, char c)
{
    int i;
    int j;
    char    src[2];

    src[0] = c;
    src[1] = 0;
    j = ft_strlen(dest);
    i = 0;
    while (src[i])
    {
        dest[j + i] = src[i];
        i++;
    }
    return (dest);
}
