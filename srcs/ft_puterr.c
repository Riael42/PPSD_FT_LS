/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:41:32 by mcutura           #+#    #+#             */
/*   Updated: 2023/03/11 13:42:04 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puterr(char *progname, char *errmsg, char errparam)
{
	if (progname)
		while (*progname)
			write(2, progname++, 1);
	write(2, ": ", 2);
	if (errmsg)
		while (*errmsg)
			write(2, errmsg++, 1);
	write(2, "'", 1);
	if (errparam)
			write(2, &errparam, 1);
	write(2, "'", 1);
}
