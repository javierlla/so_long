/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checkmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:51:54 by jllarena          #+#    #+#             */
/*   Updated: 2024/01/29 16:51:55 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

int	ft_checkmap_wall(t_map *m)
{
	ft_init_m(m);
	while (m->str[m->i])
	{
		if (m->i == 0 || m->i == m->num_lines - 1)
		{
			while (m->str[m->i][m->j] == '1')
				m->j++;
			if (m->j != m->width)
				return (-1);
		}
		m->j = 0;
		if (m->i > 0 && m->i < m->num_lines - 1)
		{
			if (m->str[m->i][m->j] != '1'
			|| (m->str[m->i][m->width - 1] != '1'))
				return (-1);
		}
		m->i++;
	}
	return (ft_checkmap_path_findpos(m));
}

int	ft_checkmap_num_comps(t_map *m)
{
	if (m->exit != 1 || m->position != 1)
		return (-1);
	else if (m->c_coin < 1)
		return (-1);
	else
		return (0);
}

int	ft_checkmap_comps(t_map *m)
{
	m->i = 0;
	while (m->i < m->len_map)
	{
		if (m->map[m->i] == '1' || m->map[m->i] == '0'
			|| m->map[m->i] == '\n')
			m->i++;
		else if (m->map[m->i] == 'C')
		{
			m->i++;
			m->c_coin++;
		}
		else if (m->map[m->i] == 'E')
		{
			m->i++;
			m->exit++;
		}
		else if (m->map[m->i] == 'P')
		{
			m->i++;
			m->position++;
		}
		else
			return (-1);
	}
	return (ft_checkmap_num_comps(m));
}

int	ft_checkmap_form(t_map *m)
{
	ft_init_m(m);
	while (m->map[m->i] != '\n' && m->map[m->i] != 0)
		m->i++;
	m->width = m->i;
	m->i = 0;
	while (m->i < m->len_map + 1)
	{
		while (m->map[m->i] != '\n' && m->map[m->i] != 0)
		{
			m->i++;
			m->j++;
		}
		m->i++;
		while (m->map[m->i] != '\n' && m->map[m->i] != 0)
		{
			m->i++;
			m->c++;
		}
		if (m->j == m->c || ((m->map[m->i]) == 0
				&& (m->j - m->c) == m->width))
			m->i++;
		else
			return (-1);
	}
	return (ft_checkmap_comps(m));
}
