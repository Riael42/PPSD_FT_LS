/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:44:49 by riael             #+#    #+#             */
/*   Updated: 2023/03/06 18:02:49 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

void	ft_proc_args(int argc, char **argv)
{
	char	flags[53]; //hard cap at 26 * 2 flags
	char	names[100][100]; //hard cap at 100 files with 100 max name length
	int	bitshift;
	//u_bitshift *bitshift;

	ft_get_flags(flags, argc, argv);
	ft_get_names(names, argc, argv);
	if (flags[0] == '-1')
		return ;
	if (names[0][0] == '/')
		return ;
	bitshift = ft_get_bitshift(flags);
	//ft_get_bitshift(flags)
	ft_start_ls(bitshift, names);
}
