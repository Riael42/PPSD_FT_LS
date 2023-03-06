/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:30:49 by riael             #+#    #+#             */
/*   Updated: 2023/03/06 18:06:07 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

void	ft_get_flags(char *flags, int argc, char **argv)
{
	int	argparser;
	int	flag;

	flags[0] = 42;
	flags[1] = '\0'; 
	while (argc > 1)
	{
		ft_flag_arg(flags, argc, argv, 1);
		argc -= 1;
	}
}
