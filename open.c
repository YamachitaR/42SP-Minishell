/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 03:39:36 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/10/08 03:57:35 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




char *get_next_line(int fd)
{
	static char	*storage;
	char		*buff;
	char		*tmp;
	char		*line;
	int			i;
	int 		j;
	
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	i = read(fd, buff, BUFFER_SIZE);
	line = NULL;
	while (i != 0)
	{
		buff[i] = '\0';
		if (!storage)
			storage = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(storage, buff);
			free (storage);
			storage = tmp;
		}
		if (ft_strchr(storage, '\n'))
		{
			j = 0;
			while (storage[j] != '\n')
				j++;
			line = ft_substr(storage, 0, j + 1);
			storage = ft_strdup(ft_strchr(storage, '\n') + 1);
//			free(tmp);
			break ;
		}
	i = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while(1)
	{
		s = get_next_line(fd);
		if (s)
		{
			printf("%s", s);
			free(s);
		}
		else
			break;
	}
}