#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void* ft_col_permissions(char* result, char* filename);

int main ()
{
	char* filename = "README.md"; 
    char result[4096] = "";

    ft_col_permissions(result, filename);
    printf("%s", result);

	return 0;
}

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char* ft_strcat_c(char* dest, char c)
{
    int	i;
    int	j;
    char src[2];

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

void* ft_col_permissions(char* result, char* filename)
{
    struct stat stats;

    // stat() returns 0 on successful operation
    if (stat(filename, &stats) == 0)
    {
        // Directory or not
        if (S_ISREG(stats.st_mode) == 0)
            ft_strcat_c(result, 'd');
        else
            ft_strcat_c(result, '-');
        // File permissions
        if (stats.st_mode && S_IRUSR)
            ft_strcat_c(result, 'r');
        else
            ft_strcat_c(result, '-');
        if (stats.st_mode && S_IWUSR)
            ft_strcat_c(result, 'w');
        else
            ft_strcat_c(result, '-');
        if (stats.st_mode && S_IXUSR)
            ft_strcat_c(result, 'x');
        else
            ft_strcat_c(result, '-');
        if (stats.st_mode && S_IRGRP)
            ft_strcat_c(result, 'r');
        else
            ft_strcat_c(result, '-');
        if (stats.st_mode && S_IWGRP)
            ft_strcat_c(result, 'w');
        else
            ft_strcat_c(result, '-');
        if (stats.st_mode && S_IXGRP)
            ft_strcat_c(result, 'x');
        else
            ft_strcat_c(result, '-');
        if (stats.st_mode && S_IROTH)
            ft_strcat_c(result, 'r');
        else
            ft_strcat_c(result, '-');
        if (stats.st_mode && S_IWOTH)
            ft_strcat_c(result, 'w');
        else
            ft_strcat_c(result, '-');
        if (stats.st_mode && S_IXOTH)
            ft_strcat_c(result, 'x');
        else
            ft_strcat_c(result, '-');

    }
    // If stats() returns -1, was unable to get file properties.
    else
        write(1, "Unable to get properties.\n", 26);
}
