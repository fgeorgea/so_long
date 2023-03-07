/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:53:46 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/07 15:40:11 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	red_cross(t_game *g)
{
	ft_clear_imgs(g);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_pressed(int key, t_game *g)
{
	char	*move;

	if (key == KEY_ESC)
		red_cross(g);
	mlx_clear_window(g->mlx, g->mlx_win);
	ft_movement(key, g);
	move = ft_itoa(g->player.move);
	if (!move)
	{
		ft_clear_imgs(g);
		ft_error(-1, NULL, g->map.map, ERR_MEMORY);
	}
	mlx_string_put(g->mlx, g->mlx_win, g->w_width - 50, 15, 0xFFFFFF, move);
	if (g->player.move < 2)
		ft_putstr_fd("Step : ", 1);
	else
		ft_putstr_fd("Steps : ", 1);
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
	free(move);
	ft_display_imgs(g);
	return (0);
}
