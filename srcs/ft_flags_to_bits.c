/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_to_bits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:14:19 by mcutura           #+#    #+#             */
/*   Updated: 2023/03/09 20:23:31 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO - Implement multi-bit flipping logic and rework Macros into usable masks
// OPTIONS FLAGS
#define FLAG_RECURSIVE (1 << 'R' - 63)
#define FLAG_ALL (1 << 'a' - 63)
#define FLAG_ALMOSTALL (1 << 'A' - 63)
#define FLAG_INODE (1 << 'i' - 63)
#define FLAG_HUMAN (1 << 'h' - 63)
#define FLAG_REVERSE (1 << 'r' - 63)
#define FLAG_XLINE (1 << 'x' - 63)
#define FLAG_COMMALIST (1 << 'm' - 63)
#define FLAG_ONELINE (1 << 1)
#define FLAG_LONGLIST (1 << 'l' - 63)
#define FLAG_NOOWNER (1 << 'g' - 63)
#define FLAG_NOGROUP (1 << 'G' - 63)
#define FLAG_NUMID (1 << 'n' - 63)
#define FLAG_NOGROUPINFO (1 << 'o' - 63)
#define FLAG_DIRECTORY (1 << 'd' - 63)
// SORTING FLAGS
#define FLAG_SORT_CHANGETIME (1 << 'c' - 63)
#define FLAG_SORT_DIRORDER (1 << 'f' - 63)
#define FLAG_SORT_TIME (1 << 't' - 63)
#define FLAG_SORT_ACCESSTIME (1 << 'u' - 63)
#define FLAG_SORT_VERSION (1 << 'v' - 63)
#define FLAG_SORT_FILESIZE (1 << 'S' - 63)
#define FLAG_SORT_UNSORTED (1 << 'U' - 63)
#define FLAG_SORT_XTENSION (1 << 'X' - 63)

// THIS DOESNT BELONG HERE
int	is_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_flags_to_bits(long *bitflags, unsigned char *flags)
{
	if (flags)
	{
		*bitflags = 0l;
		while (*flags)
		{
			if (is_alpha(*flags))
				*bitflags |= 1l << *flags - '?';
			else if (*flags == '1')
				*bitflags |= FLAG_ONELINE;
			flags++;
		}
	}
	return (0);
}
