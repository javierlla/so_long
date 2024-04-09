/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:52:57 by jllarena          #+#    #+#             */
/*   Updated: 2024/02/02 12:34:14 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mapcheck_malloc_error(void)
{
	write (2, "Error allocating memory for the check\n", 36);
	return (-2);
}

int	ft_put_lines(t_map *m)
{
	size_t	i;
	int		j;

	i = 0;
	j = 1;
	m->str[0] = m->map;
	while (j < m->num_lines)
	{
		while (m->map[i] != '\n')
			i++;
		if (m->map[i] == '\n')
		{
			m->map[i] = 0;
			i++;
			m->str[j] = &m->map[i];
		}
		j++;
	}
	return (ft_checkmap_wall(m));
}

int	ft_count_lines(t_map *m)
{
	size_t	init;
	size_t	count;
	size_t	final;

	init = 0;
	final = 0;
	count = 0;
	while (m->map[init])
	{
		init = final;
		while (m->map[init] == '\n' && m->map[init] != 0)
			init++;
		if (m->map[init] != '\n' && m->map[init] != 0)
			count++;
		final = init;
		while (m->map[final] != '\n' && m->map[final] != 0)
			final++;
		init = final;
	}
	m->str = malloc(sizeof (char *) * (count + 1));
	if (m->str == 0)
		return (ft_mapcheck_malloc_error());
	m->str[count] = 0;
	m->num_lines = count;
	return (ft_put_lines(m));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	ft_init_m(t_map *m)
{
	m->c = 0;
	m->i = 0;
	m->j = 0;
	m->y = 0;
}
