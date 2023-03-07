/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kush <d.wilke7755@googlemail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:28:26 by kush              #+#    #+#             */
/*   Updated: 2023/03/07 04:46:14 by kush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "../includes/ft_ls.h"

char    *ft_strcat(char *dest, char *src);
void    ft_putstr(char *str);
int     ft_strcmp(char *s1, char *s2);

int	get_data_count(char *dir_str)
{
	int	count;
	DIR	*dir;
	struct dirent   *dir_ent;

	count = 0;
	dir = opendir(dir_str);
	if (dir == NULL)
		return (-1);
	dir_ent = readdir(dir);
	while (dir_ent != NULL)
	{
		if (dir_ent->d_name[0] != '.')
			count++;
		dir_ent = readdir(dir);
	}
	closedir(dir);
	return (count);
}

int	ft_get_time_date(char *result, char *filename)
{
	struct stat	stats;
	int	err_ind;

	err_ind = stat(filename, &stats);
	if (err_ind == -1)
		return (-1);
	printf("%s", ctime(&stats.st_mtime));
	return (0);
}

void	sort_by_name(char **strings, int size)
{
	char	*tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size-1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(strings[i], strings[j]) > 0)
			{
				tmp = strings[i];
				strings[i] = strings[j];
				strings[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

char	**get_names_array(char *path, int size)
{
	char	**names;
	DIR	*dir;
	struct dirent	*dir_ent;
	int	i;

	names = malloc(sizeof(char *) * size);
	dir = opendir(path);
	dir_ent = readdir(dir);
	i = 0;
	while (dir_ent != NULL)
	{
		if (dir_ent->d_name[0] != '.')
		{
			names[i] = ft_strcat("", dir_ent->d_name);
			i++;
		}
		dir_ent = readdir(dir);
	}	
	closedir(dir);
	return (names);
}

void	write_column_output(char **strings, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(strings[i]);
		if (i < size - 1)
			ft_putstr("  ");
		i++;
	}
	ft_putstr("\n");
}

int	run_default(char *path)
{
	int	size;
	char	**names;

	size = get_data_count(path);
	if (size == -1)
	{
		ft_putstr("Error, can't read directory");
		return (0);
	}
	names = get_names_array(path, size);
	sort_by_name(names, size);
	write_column_output(names, size);
	// free names
	return (0);
}

int	run_default_old(void)
{
	DIR	*dir;
	char	*teststr;
	struct dirent	*dir_ent;
	int names;
	char **strings;
	int	i;

	i = 0;
	names = get_data_count(".");
	if (names == -1)
		return (-1);
	dir = opendir(".");
	dir_ent = readdir(dir);
	strings = malloc(sizeof(char *) * names);
	while (dir_ent != NULL)
	{
		if (dir_ent->d_name[0] != '.')
		{
			strings[i] = ft_strcat("", dir_ent->d_name);
			i++;
		}
		//ft_get_time_date(teststr, dir_ent->d_name);
		dir_ent = readdir(dir);
	}
	sort_by_name(strings, names);
	i = 0;
	while (i < names)
	{
		ft_putstr(strings[i]);
		if (i < names - 1)
			ft_putstr("  ");
		i++;
	}
	ft_putstr("\n");
	closedir(dir);
}
