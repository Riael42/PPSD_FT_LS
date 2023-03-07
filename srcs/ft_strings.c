/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kush <d.wilke7755@googlemail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:01:40 by kush              #+#    #+#             */
/*   Updated: 2023/03/06 19:39:37 by kush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
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

/*
int	main(void)
{
	char *str;
	char *str2;

	str = ft_strcat("", "");
	str2 = ft_strcat("", "");
	ft_putstr(str);
	ft_putstr("\n");
	printf("strcmp: %d\n", ft_strcmp(str, str2));
	free(str);
	free(str2);
	return (0);
}
*/
