/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:23:23 by riael             #+#    #+#             */
/*   Updated: 2023/03/06 16:37:01 by kush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

void	ft_proc_args(int argc, char **argv);
int	run_default(void);

int	main(int argc, char **argv)
{
	argv[0][0] += 1;
	if (argc == 1)
	{
		write(1, "Running default LS config\n", 26);
		run_default();
	}
	else
		ft_proc_args(argc, argv);
	return (0);
}
