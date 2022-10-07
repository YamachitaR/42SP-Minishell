/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:35:30 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 00:36:03 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	**ft_strstrdup(char **src)
{
	char	**dst;
    int     i;

	dst =  (char **) malloc((ft_strstrlen(src) + 1)*sizeof(char **) );
	if (dst == NULL)
		return (NULL);
    
    i = 0;
    while(src[i])
    {
        dst[i] = ft_strdup(src[i]);
        i ++;
    }
	dst[i] = NULL;
	return (dst);
}