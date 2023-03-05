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
	int	num;

	num = 1;
	while (num < argc)
	{
		if (argv[num][0] == '-') //if argv[num][1] == '-' check advanced flags for errors
			if (ft_check_flag(argv[num]) == 0)
			{
				write(1, "Error not a valid flag", 21);
				return ;
			}
		num += 1;
	}
}
