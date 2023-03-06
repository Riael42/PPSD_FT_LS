/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riael <Don't quit! | #42gether>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:30:49 by riael             #+#    #+#             */
/*   Updated: 2023/03/06 09:43:50 by riael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_ls.h"

void  ft_get_flags(char *flags, int max, char **argv)
{
        int     argc;
        int     argparser;
        int     flag;
        
        argc = 1;
        while (argc < max)
        {
                argparser = 1;
                if (argv[argc][0] == '-')
                        while (argv[argc][argparser] != '\0')
                        {
                                flags[argv[argc][argparser] - 'A'] = 1;
                                argparser += 1;
                        }
                argc += 1;
        }
}
