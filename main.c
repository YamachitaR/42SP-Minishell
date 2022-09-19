/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:46:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/09/14 14:34:12 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


	int g_on;


int	main(int argc, char **argv, char **env)
{
	// check os arg
	check_arg(argc, argv,env);


	g_on = 1;
	while(g_on)
	{

	}



	return (0);
}
