/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:14:51 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 05:39:06 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void print_strstr(char **str);
void command(t_data *data)
{
    char **split;

    split =ft_split_quote(data->line, '|');

    print_strstr(split);
    ft_free_strstr(split);
    ft_putstr_fd(data->line, 1);
    
}





void print_strstr(char **str)
{
    int i;
    
    i = 0;
    while(str[i])
        ft_putendl_fd(str[i++], 1);
}