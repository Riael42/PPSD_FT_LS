/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <#42gether | home@42berlin>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:01:10 by riael             #+#    #+#             */
/*   Updated: 2023/03/06 18:17:42 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

void	ft_flag_arg(char *flags, int argc, char **argv, int argpar)
{
	int	flagcomp;
	
	while (argv[argc][argpar] != '\0')
	{
		flagcomp = 0;
		while(flagcomp < 53)
		{
			if (flags[flagcomp] == '\0')
				flags[flagcomp] = argv[argc][argpar];
			if (flags[flagcomp] == argv[argc][argpar])
				flagcomp = 4242;
			flagcomp += 1;
		}
		argpart += 1;
	}
}
