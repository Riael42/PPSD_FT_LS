/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmagiks.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:04:31 by mcutura           #+#    #+#             */
/*   Updated: 2023/03/11 12:08:00 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BITMAGIKS_H
# define FT_BITMAGIKS_H

# define LIST_MASK 111
# define LIST_OFFSET 4
# define SORT_MASK 1111
# define SORT_OFFSET 7
# define ALL_MASK 11
# define ALL_OFFSET 11

int	is_sorting_option(char c);
int	is_listing_option(char c);
int	is_other_option(char c);

#endif
