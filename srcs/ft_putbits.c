/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:23:44 by mcutura           #+#    #+#             */
/*   Updated: 2023/03/09 20:24:58 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putbits(long bits)
{
	int	i;

	i = sizeof(bits) * 8;
	while (i--)
		write(1, &"01"[(bits >> i) & 1], 1);
}