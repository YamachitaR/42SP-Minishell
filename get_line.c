/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:54:09 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 00:23:02 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*line_pwd(void);

char	*get_line(void)
{
	char	*line;
	char	*pwd;

	pwd = line_pwd ();
	line = readline(pwd);
	free(pwd);
	add_history(line);
	if (!check_line(line))
	{
		free(line);
		return (get_line ());
	}
	return (line);
}



static char	*line_pwd(void)
{

	return (ft_strdup("Minishell$"));
}
