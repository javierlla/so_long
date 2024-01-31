/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:52:50 by jllarena          #+#    #+#             */
/*   Updated: 2024/01/29 16:52:51 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

void	ft_print_moves(t_map *m)
{
	int	fd;

	fd = 1;
	m->move = m->move + 1;
	write(1, "Moves:", 6);
	ft_putnbr_fd(m->move, fd);
	write(1, "\n", 1);
}

void	ft_move_right(t_map *m)
{
	if (m->str[m->x_exit][m->y_exit] == 'P'
		&& m->str[m->player_x][m->player_y + 1] != '1')
	{
		if (m->str[m->player_x][m->player_y + 1] == 'C')
			m->c_coin--;
		ft_change_exit2(&m->str[m->x_exit][m->y_exit],
			&m->str[m->player_x][m->player_y + 1]);
		m->player_y = m->player_y + 1;
		ft_print_moves(m);
	}
	else if (m->str[m->player_x][m->player_y + 1] == 'E'
		&& m->c_coin == 0)
	{
		ft_print_moves(m);
		ft_exit_rb(m);
	}
	else if (m->str[m->player_x][m->player_y + 1] != '1')
	{
		if (m->str[m->player_x][m->player_y + 1] == 'C')
			m->c_coin--;
		ft_change_img(&(m->str[m->player_x][m->player_y]),
			&(m->str[m->player_x][m->player_y + 1]));
		m->player_y = m->player_y + 1;
		ft_print_moves(m);
	}
}

void	ft_move_down(t_map *m)
{
	if (m->str[m->x_exit][m->y_exit] == 'P'
		&& m->str[m->player_x + 1][m->player_y] != '1')
	{
		if (m->str[m->player_x + 1][m->player_y] == 'C')
			m->c_coin--;
		ft_change_exit2(&m->str[m->x_exit][m->y_exit],
			&m->str[m->player_x + 1][m->player_y]);
		m->player_x = m->player_x + 1;
		ft_print_moves(m);
	}
	else if (m->str[m->player_x + 1][m->player_y] == 'E'
		&& m->c_coin == 0)
	{
		ft_print_moves(m);
		ft_exit_rb(m);
	}
	else if (m->str[m->player_x + 1][m->player_y] != '1')
	{
		if (m->str[m->player_x + 1][m->player_y] == 'C')
			m->c_coin--;
		ft_change_img(&(m->str[m->player_x][m->player_y]),
			&(m->str[m->player_x + 1][m->player_y]));
		m->player_x = m->player_x + 1;
		ft_print_moves(m);
	}
}

void	ft_move_left(t_map *m)
{
	if (m->str[m->x_exit][m->y_exit] == 'P'
		&& m->str[m->player_x][m->player_y - 1] != '1')
	{
		if (m->str[m->player_x][m->player_y - 1] == 'C')
			m->c_coin--;
		ft_change_exit2(&m->str[m->x_exit][m->y_exit],
			&m->str[m->player_x][m->player_y - 1]);
		m->player_y = m->player_y - 1;
		ft_print_moves(m);
	}
	else if (m->str[m->player_x][m->player_y - 1] == 'E'
		&& m->c_coin == 0)
	{
		ft_print_moves(m);
		ft_exit_rb(m);
	}
	else if (m->str[m->player_x][m->player_y - 1] != '1')
	{
		if (m->str[m->player_x][m->player_y - 1] == 'C')
			m->c_coin--;
		ft_change_img(&(m->str[m->player_x][m->player_y]),
			&(m->str[m->player_x][m->player_y - 1]));
		m->player_y = m->player_y -1;
		ft_print_moves(m);
	}
}

void	ft_move_up(t_map *m)
{
	if (m->str[m->x_exit][m->y_exit] == 'P'
		&& m->str[m->player_x - 1][m->player_y] != '1')
	{
		if (m->str[m->player_x - 1][m->player_y] == 'C')
			m->c_coin--;
		ft_change_exit2(&m->str[m->x_exit][m->y_exit],
			&m->str[m->player_x - 1][m->player_y]);
		m->player_x = m->player_x - 1;
		ft_print_moves(m);
	}
	else if (m->str[m->player_x - 1][m->player_y] == 'E'
		&& m->c_coin == 0)
	{
		ft_print_moves(m);
		ft_exit_rb(m);
	}
	else if (m->str[m->player_x - 1][m->player_y] != '1')
	{
		if (m->str[m->player_x - 1][m->player_y] == 'C')
			m->c_coin--;
		ft_change_img(&(m->str[m->player_x][m->player_y]),
			&(m->str[m->player_x - 1][m->player_y]));
		m->player_x = m->player_x - 1;
		ft_print_moves(m);
	}
}
/*void	ft_move_down(t_map *m)
{
	if (m->str[m->x_exit][m->y_exit] == 'P'
		&& m->str[m->player_x + 1][m->player_y] != '1')
	{
		if (m->str[m->player_x + 1][m->player_y] == 'C')
			m->c_coin--;
		ft_change_exit2(&m->str[m->x_exit][m->y_exit],
			&m->str[m->player_x + 1][m->player_y]);
		m->player_x = m->player_x + 1;
		ft_print_moves(m);
	}
	else if (m->str[m->player_x + 1][m->player_y] == 'E'
		&& m->c_coin == 0)
	{
		ft_print_moves(m);
		ft_exit_rb(m);
	}
	else if (m->str[m->player_x + 1][m->player_y] != '1')
	{
		if (m->str[m->player_x + 1][m->player_y] == 'C')
			m->c_coin--;
		ft_change_img(&(m->str[m->player_x][m->player_y]),
			&(m->str[m->player_x + 1][m->player_y]));
		m->player_x = m->player_x + 1;
		ft_print_moves(m);
	}
}*/