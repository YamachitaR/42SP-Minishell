/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:53:21 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 19:47:25 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"
int ft_cd(char **cmd);

int build(char **cmd)
{
    if(ft_strncmp(cmd[0], "cd", 2)==0)
        return(ft_cd(cmd));


    return(0);

    
}


int ft_cd(char **cmd)
{
    if(cmd[1])
        ft_putstr_fd(cmd[1], 1);
    ft_putendl_fd("Três CD eh um real", 1);
    return(1);
}