/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:54:26 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/02/09 15:54:27 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img(t_game *g)
{
	g->img.wall = mlx_xpm_file_to_image(g->mlx,
			"./img/wall.xpm", &g->img.img_width, &g->img.img_height);
	g->img.floor = mlx_xpm_file_to_image(g->mlx,
			"./img/floor.xpm", &g->img.img_width, &g->img.img_height);
	g->img.player_floor = mlx_xpm_file_to_image(g->mlx,
			"./img/player_floor.xpm", &g->img.img_width, &g->img.img_height);
	g->img.player_exit = mlx_xpm_file_to_image(g->mlx,
			"./img/player_exit.xpm", &g->img.img_width, &g->img.img_height);
	g->img.coin = mlx_xpm_file_to_image(g->mlx,
			"./img/coin.xpm", &g->img.img_width, &g->img.img_height);
	g->img.dclose = mlx_xpm_file_to_image(g->mlx,
			"./img/dclose.xpm", &g->img.img_width, &g->img.img_height);
	g->img.dopen = mlx_xpm_file_to_image(g->mlx,
			"./img/dopen.xpm", &g->img.img_width, &g->img.img_height);
	if (!g->img.coin || !g->img.dclose || !g->img.dopen || !g->img.floor
		|| !g->img.player_exit || !g->img.player_floor || !g->img.wall)
	{
		ft_destroy_all_img(g);
		ft_error(-1, NULL, NULL, ERR_INIT_IMG);
	}
}

void	ft_put_img(t_game *g, int x, int y, const char c)
{
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.wall,
			y * 32, (x * 32) + 20);
	if (c == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.floor,
			y * 32, (x * 32) + 20);
	if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player_floor,
			y * 32, (x * 32) + 20);
	if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.coin,
			y * 32, (x * 32) + 20);
	if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.dclose,
			y * 32, (x * 32) + 20);
	if (c == 'e')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.dopen,
			y * 32, (x * 32) + 20);
	if (c == 'p')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player_exit,
			y * 32, (x * 32) + 20);
}

static void	ft_put_img_map2(t_game *g, int i, int j)
{
	if (g->map.map[i][j] == '1')
		ft_put_img(g, i, j, '1');
	else if (g->map.map[i][j] == '0')
		ft_put_img(g, i, j, '0');
	else if (g->map.map[i][j] == 'P'
		&& g->player.pos_y == g->check.exit_pos_y
		&& g->player.pos_x == g->check.exit_pos_x
		&& g->check.nbr_coin != g->player.coin_collected)
		ft_put_img(g, i, j, 'p');
	else if (g->map.map[i][j] == 'P')
		ft_put_img(g, i, j, 'P');
	else if (g->map.map[i][j] == 'C')
		ft_put_img(g, i, j, 'C');
	else if (g->map.map[i][j] == 'E'
	&& g->check.nbr_coin == g->player.coin_collected)
		ft_put_img(g, i, j, 'e');
	else if (g->map.map[i][j] == 'E')
		ft_put_img(g, i, j, 'E');
}

void	ft_put_img_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (g->map.map[i][++j])
			ft_put_img_map2(g, i, j);
	}
}

void	ft_destroy_all_img(t_game *g)
{
	if (g->img.coin)
		mlx_destroy_image(g->mlx, g->img.coin);
	if (g->img.dclose)
		mlx_destroy_image(g->mlx, g->img.dclose);
	if (g->img.dopen)
		mlx_destroy_image(g->mlx, g->img.dopen);
	if (g->img.floor)
		mlx_destroy_image(g->mlx, g->img.floor);
	if (g->img.player_exit)
		mlx_destroy_image(g->mlx, g->img.player_exit);
	if (g->img.player_floor)
		mlx_destroy_image(g->mlx, g->img.player_floor);
	if (g->img.wall)
		mlx_destroy_image(g->mlx, g->img.wall);
}
