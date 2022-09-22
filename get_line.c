/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:54:09 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/09/22 00:25:17 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_line (char *line);
static int	check_quote(char *line);
static int	check_special(char *line);


char	*get_line(void)
{
	char	*line;

	line = readline("Minishell~$ ");
	if (!line)
		get_line();
	add_history(line);
	if(!check_line(line))
		get_line();
	return (line);
}

static int	check_line (char *line)
{
	if(!check_quote(line))
	{
		ft_putstr_fd("missing quote\n", 1);
		return (0);
	}

	if(!check_special(line))
	{
		ft_putstr_fd("special\n", 1);
		return (0);
	}
	return (1);
}

static int	check_quote(char	*line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			if(!ft_strchr(&line[i + 1], line [i]))
				return (0);
			i += ft_strlen(&line[i]) - ft_strlen(ft_strchr(&line[i + 1],line[i]));
		}
		if(line[i])
			i ++;
	}
	return (1);
}

static int	check_special(char	*line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if ((ft_strchr(SPECIAL, line[i])))
			return (0);
		if (line[i] == '\"' || line[i] == '\'')
		{
			i += ft_strlen(&line[i]) - ft_strlen(ft_strchr(&line[i + 1], line[i]));
		}
		if(line[i])
			i ++;
	}
	return (1);
}

