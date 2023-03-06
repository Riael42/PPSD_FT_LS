/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kush <d.wilke7755@googlemail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:28:26 by kush              #+#    #+#             */
/*   Updated: 2023/03/06 16:52:35 by kush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include "../includes/ft_ls.h"

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

int	run_default(void)
{
	DIR	*dir;
	char	*teststr;
	struct dirent	*dir_ent;

	dir = opendir(".");
	if (dir == NULL)
		return (-1);
	dir_ent = readdir(dir);
	while (dir_ent != NULL)
	{
		if (dir_ent->d_name[0] != '.')
			printf("%s\t", dir_ent->d_name);
		//ft_get_time_date(teststr, dir_ent->d_name);
		dir_ent = readdir(dir);
	}
	printf("\n");
	closedir(dir);
}
