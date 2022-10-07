/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:46:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 01:02:38 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*g_data;

int	main(int argc, char **argv, char **env)
{
	check_arg(argc, argv, env);
	initialize(env);
	while(g_data->on)
	{
		g_data->line = get_line();
		ft_putendl_fd(g_data->line, 1);
		if(ft_strncmp(g_data->line, "exit", 4 )==0)
			g_data->on = 0;
		free(g_data->line);
	}
	rl_clear_history();

	return (0);
}

void initialize(char **env)
{

	g_data = (t_data *) malloc (sizeof(t_data));
	g_data->on = 1;
	g_data->env_original = env;
	g_data->env_copy = ft_strstrdup(env);

}