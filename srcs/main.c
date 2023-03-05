/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:23:23 by riael             #+#    #+#             */
/*   Updated: 2023/03/05 12:46:33 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

int	main(int argc, char **argv)
{
	argv[0][0] += 1;
	if (argc == 1)
		write(1, "Running default LS config\n", 26);
	else
		write(1, "Analysing flags\n", 16);
	return (0);
}
