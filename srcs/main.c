/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:23:23 by riael             #+#    #+#             */
/*   Updated: 2023/03/05 13:46:40 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "Running default LS config\n", 26);
	else
		ft_proc_args(argc, argv);
	return (0);
}
