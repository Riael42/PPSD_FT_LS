/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagchecks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:51:15 by mcutura           #+#    #+#             */
/*   Updated: 2023/03/10 21:06:09 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_other_option(char c)
{
	if (c == 'R')
		return (8);
	if (c == 'a' || c == 'A')
		return (1);
	if (c == 'i' || c == 'h' || c == 'n' || c == 'G')
		return (-1);
	if (c == 'd')
		return (11);
	return (0);
}

int	is_listing_option(char c)
{
	if (c == 'x' || c == 'm' || c == '1')
		return (1);
	if (c == 'l' || c == 'g' || c == 'o')
		return (-1);
	return (0);
}

int	is_sorting_option(char c)
{
	if (c == 'c' || c == 'f' || c == 't' || c == 'u')
		return (1);
	if (c == 'v' || c == 'S' || c == 'U' || c == 'X')
		return (-1);
	if (c == 'r')
		return (2);
	return (0);
}
