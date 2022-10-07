/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:59:24 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 00:09:10 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_command_path(char **path, char *cmd);


int	ft_execve(char **split_cmd, char **env)
{
	char	**path;
	char	*command_path;

	path = ft_split(getenv("PATH"), ':');
	if (!path)
	{
		ft_putendl_fd("Not found path", STDERR);
		exit(EXIT_FAILURE);
	}
	command_path = find_command_path(path, split_cmd[0]);
	if (command_path)
		execve(command_path, split_cmd, env);
	ft_free_strstr(path);
	free(command_path);
	return (-1);
}

static char	*find_command_path(char **path, char *cmd)
{
	char	*cmd_path;
	char	*temp;
	int		i;

	if (ft_strchr(cmd, '/') != NULL && access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (path[i] != NULL)
	{
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

