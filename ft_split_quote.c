/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:28:45 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 05:49:46 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char isnnot_char(char *str, char c);
static char *str_change(char *s, char c);

char    **ft_split_quote(char *str, char special)
{
    char    **split;
    char    *s;
    int     i;
    int     j;
    
    if (!(ft_strchr(str, special)) || (!ft_strchr(str,'\"') && !ft_strchr(str,'\'')))
        return (ft_split(str, special));
    s = str_change(str, special);
    split = ft_split(s, special);
    free (s);
    i = -1;
    while (split[++i])
    {
        j = -1;
        while (split[i][++j])
        {
            if (split[i][j] == isnnot_char(str, special))
                split[i][j]=special;
        }
    }
    return (split);
}

static char *str_change(char *s, char c)
{
    int     i;
    char    *str;
    char    quote;
    char    not_char;

    not_char = isnnot_char(s, c);
    str = ft_strdup(s);
    i = 0;
    while(str[i])
    {
        if(str[i]== '"'|| str[i]== '\'' )
        {
            quote = str[i ++];
            while (str[i] != quote)
            {
                if (str[i] == c)
                    str[i] = not_char;
                i ++;
            }
        }
        i ++;
    }
    return (str);
}

static char isnnot_char(char *str, char c)
{
    char    isnot;

    isnot = '0';
    while (ft_strchr(str, isnot) != NULL || isnot == c)   
        isnot ++;
    return (isnot);
}
