/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:38:11 by riael             #+#    #+#             */
/*   Updated: 2023/03/05 17:43:12 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_ls.h"

void	ft_build_line(char *result, int *flags, int flagnum, char *filename)
{
	int	currnum;

	currnum = 0;
	while (currnum < flagnum)
	{
		if (flags[currnum] < 5)
			ft_append_line_a(result, flags[currnum]);
		if (flags[currnum] >= 5 && flags[currnum] < 10)
			ft_append_line_b(reult, flags[currnum]);
		if (flags[currnum] >= 10 && flags[currnum] < 15)
			ft_append_line_c(result, flags[currnum]);
		currnum += 1;
	}
}
