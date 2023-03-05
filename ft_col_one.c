#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char *ft_col_one(char* filename);

int main ()
{
	char* filename = "help.txt";
    char* col_one;
    
    col_one = ft_col_one(filename);

    int i = 0;
    while (col_one[i] != '\0')
    {
        printf("%c", col_one[i]);
        i++;
    }

    free(col_one);
	return 0;
}

char* ft_col_one(char* filename)
{
    struct stat stats;
    char* col_one;
    int i;

    col_one = (char*)malloc(sizeof(char) * 10); //1 for dir and 3 for each user, group and others.
    if (col_one == NULL)
    {
        write(1, "Error\n", 6);
        return NULL;
    }
    // stat() returns 0 on successful operation
    if (stat(filename, &stats) == 0)
    {
        // Directory or not
        if (S_ISREG(stats.st_mode) == 0)
            col_one[0] = 'd';
        // File permissions
        if (stats.st_mode && S_IRUSR)
            col_one[1] = 'r';
        if (stats.st_mode & S_IWUSR)
            col_one[2] = 'w';
        if (stats.st_mode & S_IXUSR)
            col_one[3] = 'x';
        if (stats.st_mode && S_IRGRP)
            col_one[4] = 'r';
        if (stats.st_mode & S_IWGRP)
            col_one[5] = 'w';
        if (stats.st_mode & S_IXGRP)
            col_one[6] = 'x';
        if (stats.st_mode && S_IROTH)
            col_one[7] = 'r';
        if (stats.st_mode & S_IWOTH)
            col_one[8] = 'w';
        if (stats.st_mode & S_IXOTH)
            col_one[9] = 'x';
        // Fill up the empties with '-'
        i = 0;
        while (i < 10)
        {
            if (col_one[i] == 0)
                col_one[i] = '-';
            i++;
        }
    }
    // If stats() returns -1, was unable to get file properties.
    else
    {
        write(1, "Unable to get properties.\n", 26);
    }
    return (col_one);
}