/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_to_bits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:14:19 by mcutura           #+#    #+#             */
/*   Updated: 2023/03/10 21:09:18 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO - Create header info and move defines into header
// bits : 0, 1, 2 - reserved bits
// 3 - R - list recursively
// 4-6 - x(000), m(010), 1(001), unasigned(110)?, l(111), g(101), o(110)
// 7-10 - various sorting options (5 combinations still unassigned)
// 11-12 - a&A - list all a(11), ignore . and .. A(01)
// 13 - i - also list inode number
// 14 - h - show sizes in human friendly form
// 15 - n - show ID numbers for groups and users
// 16 - G - hide group info on long listing
// 17 - d - directory ???
// 18-32 - free to assign for sorting and other options

#include "ft_ls.h"

#define LIST_MASK 111
#define LIST_OFFSET 4
#define SORT_MASK 1111
#define SORT_OFFSET 7
#define ALL_MASK 11
#define ALL_OFFSET 11

void	set_other_option(int *bits, char c)
{
	if (is_other_option(c) > 0)
	{
		if (c == 'a' || c == 'A')
		{
			*bits &= ~(ALL_MASK << ALL_OFFSET);
			*bits |= 1 << ALL_OFFSET;
			if (c == 'a')
				*bits |= 11 << ALL_OFFSET;
		}
		else if (c == 'R')
			*bits |= 1 << 3;
		else if (c == 'd')
			*bits |= 1 << 17;
	}
	else
	{
		if (c == 'i')
			*bits |= 1 << 13;
		else if (c == 'h')
			*bits |= 1 << 14;
		else if (c == 'n')
			*bits |= 1 << 15;
		else if (c == 'G')
			*bits |= 1 << 16;
	}
}

void	set_listing_option(int *bits, char c)
{
	*bits &= ~(LIST_MASK << LIST_OFFSET);
	if (is_listing_option(c) > 0)
	{
		if (c == 'm')
			*bits |= (010 << LIST_OFFSET);
		else if (c == '1')
			*bits |= (001 << LIST_OFFSET);
	}
	else
	{
		if (c == 'l')
			*bits |= (111 << LIST_OFFSET);
		else if (c == 'g')
			*bits |= (101 << LIST_OFFSET);
		else if (c == 'o')
			*bits |= (110 << LIST_OFFSET);
	}
}

void	set_sorting_option(int *bits, char c)
{
	*bits &= ~(SORT_MASK << SORT_OFFSET);
	if (is_sorting_option(c) > 0)
	{
		if (c == 'c')
			*bits |= (0001 << SORT_OFFSET);
		else if (c == 't')
			*bits |= (0010 << SORT_OFFSET);
		else if (c == 'f')
			*bits |= (0011 << SORT_OFFSET);
		else if (c == 'u')
			*bits |= (0100 << SORT_OFFSET);
	}
	else
	{
		if (c == 'v')
			*bits |= (1001 << SORT_OFFSET);
		else if (c == 'S')
			*bits |= (1010 << SORT_OFFSET);
		else if (c == 'U')
			*bits |= (1011 << SORT_OFFSET);
		else if (c == 'X')
			*bits |= (1100 << SORT_OFFSET);
		else if (c == 'r')
			*bits |= (1111 << SORT_OFFSET);
	}
}

int	ft_flags_to_bits(int *bitflags, unsigned char *flags)
{
	if (flags)
	{
		while (*flags)
		{
			if (is_listing_option(*flags))
				set_listing_option(bitflags, *flags);
			else if (is_sorting_option(*flags))
				set_sorting_option(bitflags, *flags);
			else if (is_other_option(*flags))
				set_other_option(bitflags, *flags);
			flags++;
		}
	}
	return (0);
}
