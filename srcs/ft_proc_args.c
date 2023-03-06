/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:44:49 by riael             #+#    #+#             */
/*   Updated: 2023/03/05 13:52:25 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

void	ft_proc_args(int argc, char **argv)
{
	char	flags[52]; //hard cap at 26 * 2 flags
	char	names[100][100]; //hard cap at 100 files with 100 max name length
	int	bitshift;
	//u_bitshift *bitshift;

	ft_get_flags(flags, argc, argv);
	ft_get_names(names, argc, argv);
	if (ft_check_flags(flags) == 0)
	{
		write(1, "Invalid flag error, replace this with specific flag error", 20);
		return ;
	}
	if (ft_check_names(names) == 0)
	{
		write(1, "Invalid name error, replace this with specific flag error", 20);
		return ;
	}
	bitshift = ft_get_bitshift(flags);
	//ft_get_bitshift(flags)
	ft_start_ls(bitshift, names)
}
