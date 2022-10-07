/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:14:51 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 20:39:47 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void print_strstr(char **str);
void command(t_data *data)
{
    char **split_pipe;
    char **split_space;
    int pid;

    
    split_pipe =ft_split_quote(data->line, '|');

    if(split_pipe[1]==NULL)
    {
        split_space =ft_split_quote(data->line, ' ');
        if(!build(split_space))
        {
            pid =fork();
            if(pid==0)
                ft_execve(split_space, data->env_original); 
            wait(NULL);
        }   
          ft_free_strstr(split_space);
    }
 
    
    ft_free_strstr(split_pipe);
    ft_putstr_fd(data->line, 1);
    
}

void print_strstr(char **str)
{
    int i;
    
    i = 0;
    while(str[i])
        ft_putendl_fd(str[i++], 1);
}