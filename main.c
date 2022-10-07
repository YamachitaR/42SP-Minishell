/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:46:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 20:48:42 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*g_data;

void initialize(char **env);
void free_data(void);
int	main(int argc, char **argv, char **env)
{
	check_arg(argc, argv, env);
	initialize(env);
	while(g_data->on)
	{
		g_data->line = get_line();
		if(ft_strncmp(g_data->line, "exit", 4 ) == 0 || !g_data->line)
			g_data->on = 0;
		else
			command(g_data);
		free(g_data->line);
	}
	free_data();
	

	return (0);
}


void free_data(void)
{
	ft_free_strstr(g_data->env_copy);
	free(g_data);
	rl_clear_history();
}


void initialize(char **env)
{
	g_data = (t_data *) malloc (sizeof(t_data));
	g_data->on = 1;
	g_data->env_original = env;
	g_data->env_copy = ft_strstrdup(env);

}