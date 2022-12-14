/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:14:51 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/08 04:40:59 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int run_command(t_data *data, char *str);
void command(t_data *data)
{
 
    
    data->split_pipe =ft_split_quote(data->line, '|');
    if(data->split_pipe[1]==NULL)
        run_command(data, data->split_pipe[0]);
    else
    {
        /* 
        i=0
        while(i < ft_strstrlen(data->split_pipe) )
        {
            pipe(pipex)
            dup2// fazer uns dup doido 
            run_command(data, data->split_pipe[i]);
    
            i ++;
        }
        */
        

    }
    ft_free_strstr(data->split_space);
    ft_free_strstr(data->split_pipe);

    
}


int run_command(t_data *data, char *str)
{
    int pid;
    
    data->split_space =ft_split_quote(str, ' ');
    if(!build(data->split_space))
    {
        pid =fork();
        if(pid==0)
        {
            if(ft_execve(data->split_space, data->env_original) ==-1)
            {
              // da uma limpa  na memoria 
              exit(EXIT_FAILURE);   
            }
        }   
        if(pid > 0)    
			waitpid(pid, NULL, 0);
    }
    return(1);
}