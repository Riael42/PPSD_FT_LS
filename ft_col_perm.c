#include "FT_LS.h"

void    user_perm(char* result, struct stat stats)
{
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
}

void    group_perm(char* result, struct stat stats)
{
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
}

void    other_perm(char* result, struct stat stats)
{
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

void    *ft_col_permissions(char* result, char* filename)
{
    struct stat stats;

    if (stat(filename, &stats) == 0)
    {
        if (S_ISREG(stats.st_mode) == 0)
            ft_strcat_c(result, 'd');
        else
            ft_strcat_c(result, '-');
        user_perm(result, stats);
        group_perm(result, stats);
        other_perm(result, stats);
    }
    else
        write(1, "Unable to get properties.\n", 26);
}
