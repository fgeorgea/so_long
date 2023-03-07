/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:53:59 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/07 13:49:38 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_wall(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (++j < g->map.lenline - 1)
		{
			if (!g->map.map[i][j]
				|| g->map.map[0][j] != '1'
				|| g->map.map[g->map.nl - 1][j] != '1'
				|| g->map.map[i][0] != '1'
				|| g->map.map[i][g->map.lenline - 2] != '1')
				ft_error(-1, NULL, g->map.map, ERR_MISSING_WALL);
		}
	}
}

static void	ft_err_check_map(t_game *g)
{
	ft_check_wall(g);
	if (g->check.nbr_player > 1)
		ft_error(-1, NULL, g->map.map, ERR_NBR_PLAYER1);
	else if (g->check.nbr_player < 1)
		ft_error(-1, NULL, g->map.map, ERR_NBR_PLAYER2);
	if (g->check.nbr_exit > 1)
		ft_error(-1, NULL, g->map.map, ERR_NBR_EXIT1);
	else if (g->check.nbr_exit < 1)
		ft_error(-1, NULL, g->map.map, ERR_NBR_EXIT2);
}

static void	ft_init_pos_and_nbr_coins(t_game *g, char check, int x, int y)
{
	if (check == 'P')
	{
		g->check.nbr_player++;
		g->player.pos_y = y;
		g->player.pos_x = x;
	}
	else if (check == 'E')
	{
		g->check.nbr_exit++;
		g->check.exit_y = y;
		g->check.exit_x = x;
	}
	else if (check == 'C')
		g->check.nbr_coin++;
}

void	ft_check_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (g->map.map[i][++j])
		{
			if (g->map.map[i][j] == 'P')
				ft_init_pos_and_nbr_coins(g, 'P', j, i);
			else if (g->map.map[i][j] == 'E')
				ft_init_pos_and_nbr_coins(g, 'E', j, i);
			else if (g->map.map[i][j] == 'C')
				ft_init_pos_and_nbr_coins(g, 'C', j, i);
		}
	}
	g->check.total_obj = g->check.nbr_coin + g->check.nbr_exit;
	ft_cp_map(g);
	ft_err_check_map(g);
	if (ft_path_finding(g, g->player.pos_y, g->player.pos_x) < 0)
		ft_error(-1, NULL, g->map.map, ERR_PATH_FINDING);
	ft_free_tab(NULL, g->map.cp_map);
}
