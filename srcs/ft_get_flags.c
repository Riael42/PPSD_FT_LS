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

void  ft_get_flags(char *flags, int argc, char **argv)
{
        int     argparser;
        int     flag;
        
        while (argc > 1)
        {
                argparser = 1;
                if (argv[argc][0] == '-')
                        while (argv[argc][argparser] != '\0')
                        {
                                flag = argv[argc][argpaser] - 'A';
                                if (flag < 0 || flag > 52)
                                {
                                        flag += 'A';
                                        write(1, "Error, flag -", 12);
                                        write(1, &flag, 1);
                                        write(1, "is an invalid flag!\n", 20);
                                        flags[0] = -1;
                                        return ;
                                }
                                flags[flag] = 1;
                                argparser += 1;
                        }
                argv[argc][0] = '\0';
                argc -= 1;
        }
}
