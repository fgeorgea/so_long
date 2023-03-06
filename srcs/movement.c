/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:24:01 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/06 14:08:12 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_exit_and_coin(t_game *g)
{
	if (g->map.map[g->player.pos_y][g->player.pos_x] == 'C')
			g->player.coin_count++;
	else if (g->map.map[g->player.pos_y][g->player.pos_x] == 'E'
	&& g->check.nbr_coin == g->player.coin_count)
	{
		ft_free_tab(NULL, g->map.map);
		ft_clear_imgs(g);
		exit(EXIT_SUCCESS);
	}
}


static void	ft_move_y(char key, t_game *g)
{
	if (key == 'U')
	{
		g->player.pos_y--;
		g->player.move++;
		ft_exit_and_coin(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y + 1][g->player.pos_x] = \
		g->player.char_staged;
	}
	else if (key == 'D')
	{
		g->player.pos_y++;
		g->player.move++;
		ft_exit_and_coin(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y - 1][g->player.pos_x] = \
		g->player.char_staged;
	}
}

static void	ft_move_x(char key, t_game *g)
{
    if (key == 'L')
	{
		g->player.pos_x--;
		g->player.move++;
		ft_exit_and_coin(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x + 1] = \
		g->player.char_staged;
	}
	else if (key == 'R')
	{
		g->player.pos_x++;
		g->player.move++;
		ft_exit_and_coin(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x - 1] = \
		g->player.char_staged;
	}
}

void	ft_movement(int key, t_game *g)
{
	g->player.char_staged = '0';
	if (g->map.map[g->player.pos_y][g->player.pos_x] ==
		g->map.map[g->check.exit_y][g->check.exit_x])
			g->player.char_staged = 'E';
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	else if (g->map.map[g->player.pos_y - 1][g->player.pos_x] != '1'
			&& (key == KEY_UP))
		ft_move_y('U', g);
	else if (g->map.map[g->player.pos_y + 1][g->player.pos_x] != '1'
			&& (key == KEY_DOWN))
		ft_move_y('D', g);
        else if (g->map.map[g->player.pos_y][g->player.pos_x - 1] != '1'
			&& (key == KEY_LEFT))
		ft_move_x('L', g);
	else if (g->map.map[g->player.pos_y][g->player.pos_x + 1] != '1'
			&& (key == KEY_RIGHT))
		ft_move_x('R', g);
}
