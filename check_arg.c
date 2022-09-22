/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:18:22 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/09/21 23:54:23 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void check_arg(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("Invalid arguments", 1);
		exit(1);
	}
	if(env == NULL)
	{
		ft_putendl_fd("Error in env variable", 1);
		exit (1);
	}
}

// check os arg(s)
// simplemente para checar os argumento de entrada do main
