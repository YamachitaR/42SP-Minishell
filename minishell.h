/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:47:12 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/07 05:31:21 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define EXIT_FAILURE 1
# define EXIT_SUCESS 2
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define SPECIAL "&\\()*;"

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>



typedef struct s_data
{
	int		on;
	char	*line;
	char	**env_original;
    char    **env_copy;
	char	**split_pipe;
	char	**split_comand;
}	t_data;


void command(t_data *data);

void check_arg(int argc, char **argv, char **env);
char	*get_line(void);
void initialize(char **env);
int	check_line(char *line);
int	ft_execve(char **split_cmd, char **env);
void	ft_free_strstr(char **str);
char	**ft_strstrdup(char **src);
size_t  ft_strstrlen(char **src);
char **ft_split_quote(char *str, char special);
#endif
