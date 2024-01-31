/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:53:05 by jllarena          #+#    #+#             */
/*   Updated: 2024/01/29 16:53:06 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"
#include <stdio.h>

char	*ft_second_read_map(char *argv, int total, t_map *m)
{
	int		fd2;
	ssize_t	nb_bytes;

	fd2 = open(argv, O_RDONLY);
	if (fd2 == -1)
		return (0);
	m->map = malloc(total + 2);
	if (m->len_map == 0)
		return (0);
	nb_bytes = read (fd2, m->map, total);
	if (nb_bytes == -1)
		return (0);
	if (m->map[total - 1] != '\n')
	{
		m->map[total] = '\n';
		m->map[total + 1] = 0;
	}
	else
		m->map[total] = 0;
	if (close(fd2) == -1)
		return (0);
	return (m->map);
}

char	*ft_read(int fd, char *argv, t_map *m)
{
	int		partial;
	int		total;
	char	buf[1];

	partial = 1;
	total = 0;
	while (partial > 0)
	{
		partial = read (fd, buf, 1);
		if (partial == -1)
			return (0);
		total = total + partial;
	}
	if (close (fd) == -1)
		return (0);
	m->len_map = total;
	return (ft_second_read_map(argv, total, m));
}

char	*ft_open_map(char *argv, t_map *m)
{
	int	fd;

	fd = open (argv, O_RDONLY);
	if (fd == -1)
		return (0);
	return (ft_read(fd, argv, m));
}

int	ft_check_arg(char *argv)
{
	int	len_arg;

	len_arg = ft_strlen(argv);
	if (len_arg < 5)
		return (-1);
	else if (argv[len_arg - 1] != 'r' || argv[len_arg - 2] != 'e'
		|| argv[len_arg - 3] != 'b' || argv[len_arg - 4] != '.')
		return (-1);
	return (len_arg);
}

int	main(int argc, char **argv)
{
	t_map	m;

	m.move = 0;
	m.exit = 0;
	m.position = 0;
	m.c_coin = 0;
	m.map = ft_open_map(argv[1], &m);
	if (argc != 2 || ft_check_arg(argv[1]) == -1
		|| m.map == 0
		|| ft_checkmap_form(&m) == -1 || ft_count_lines(&m) == -1)
	{
		write(2, "Error: Invalid map\n", 19);
		return (1);
	}
	ft_start_window(&m);
	mlx_hook(m.window, 2, 0, ft_keyhook, &m);
	mlx_hook(m.window, 17, 0, ft_exit_rb, &m);
	mlx_loop(m.mlx);
	return (0);
}
