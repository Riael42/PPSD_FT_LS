/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kush <d.wilke7755@googlemail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:01:40 by kush              #+#    #+#             */
/*   Updated: 2023/03/06 17:35:48 by kush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *source)
{
	char	*ret;
	int	i;
	int	j;

	ret = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	i = 0;
	j = 0;
	while (dest[j])
	{
		ret[j] = dest[j];
		j++;
	}
	while (src[i])
	{
		ret[j] = src[i];
		i++;
		j++;
	}
	ret[j] = 0;
	return (ret);
}
