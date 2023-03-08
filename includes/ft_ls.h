/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:23:10 by riael             #+#    #+#             */
/*   Updated: 2023/03/05 12:45:40 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LS_H
# define FT_LS_H

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int	ft_strlen(char* str);
char*	ft_strcat_c(char* dest, char c);
void*	ft_col_permissions(char* result, char* filename);

#endif
