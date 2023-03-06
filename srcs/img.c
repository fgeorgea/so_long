/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:54:26 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/06 16:13:00 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img(t_game *g)
{
	g->img.wall = mlx_xpm_file_to_image(g->mlx, "./img/wall.xpm",
			&g->img.img_width, &g->img.img_height);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "./img/grass.xpm",
			&g->img.img_width, &g->img.img_height);
	g->img.player = mlx_xpm_file_to_image(g->mlx, "./img/donkeyKong.xpm",
			&g->img.img_width, &g->img.img_height);
	g->img.coin = mlx_xpm_file_to_image(g->mlx, "./img/banana.xpm",
			&g->img.img_width, &g->img.img_height);
	g->img.exit = mlx_xpm_file_to_image(g->mlx, "./img/exit.xpm",
			&g->img.img_width, &g->img.img_height);
	g->img.player_exit = mlx_xpm_file_to_image(g->mlx, "./img/player_exit.xpm",
			&g->img.img_width, &g->img.img_height);
	if (!g->img.wall || !g->img.floor || !g->img.player || !g->img.coin
		|| !g->img.exit || !g->img.player_exit)
	{
		ft_clear_imgs(g);
		ft_error(-1, NULL, NULL, ERR_INIT_IMG);
	}
}

void	ft_put_img_win(t_game *g, int x, int y, char c)
{
	if (c == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.floor,
			y * 128, (x * 128) + 20);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.wall,
			y * 128, (x * 128) + 20);
	if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player,
			y * 128, (x * 128) + 20);
	if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.coin,
			y * 128, (x * 128) + 20);
	if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.exit,
			y * 128, (x * 128) + 20);
	if (c == 'e')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player_exit,
			y * 128, (x * 128) + 20);
}

static void	ft_display_imgs2(t_game *g, int i, int j)
{
	if (g->map.map[i][j] == '0')
		ft_put_img_win(g, i, j, '0');
	else if (g->map.map[i][j] == '1')
		ft_put_img_win(g, i, j, '1');
	else if (g->map.map[i][j] == 'P'
		&& g->player.pos_y == g->check.exit_y
		&& g->player.pos_x == g->check.exit_x
		&& g->check.nbr_coin != g->player.coin_count)
		ft_put_img_win(g, i, j, 'e');
	else if (g->map.map[i][j] == 'P')
		ft_put_img_win(g, i, j, 'P');
	else if (g->map.map[i][j] == 'C')
		ft_put_img_win(g, i, j, 'C');
	else if (g->map.map[i][j] == 'E')
		ft_put_img_win(g, i, j, 'E');
	else
		return ;
}

void	ft_display_imgs(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map.map[i])
	{
		j = 0;
		while (g->map.map[i][j])
		{
			ft_display_imgs2(g, i, j);
			j++;
		}
		i++;
	}
}

void	ft_clear_imgs(t_game *g)
{
	if (g->img.wall)
		mlx_destroy_image(g->mlx, g->img.coin);
	if (g->img.floor)
		mlx_destroy_image(g->mlx, g->img.floor);
	if (g->img.player)
		mlx_destroy_image(g->mlx, g->img.player);
	if (g->img.coin)
		mlx_destroy_image(g->mlx, g->img.coin);
	if (g->img.exit)
		mlx_destroy_image(g->mlx, g->img.exit);
	if (g->img.player_exit)
		mlx_destroy_image(g->mlx, g->img.player_exit);
}
