/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:33:45 by riael             #+#    #+#             */
/*   Updated: 2023/03/05 17:43:48 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

void	*ft_proc_line(int *flags, int flagnum, char *filename)
{
	char	result[4096];
	int		i;

	ft_build_line(result, flags, flagnum, filename);
	i = ft_strlen(result);
	if (i == 0)
	{
		write(1, "LineError\n", 10);
		return ;
	}
	write(1, result, i);
}
