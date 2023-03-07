/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:53:46 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/07 17:45:33 by fgeorgea         ###   ########.fr       */
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
	if (key == KEY_ESC)
		red_cross(g);
	mlx_clear_window(g->mlx, g->mlx_win);
	ft_movement(key, g);
	if (g->player.move > 0 && (g->tmp_press != g->player.move))
	{
		if (g->player.move < 2)
			ft_putstr_fd("Step : ", 1);
		else
			ft_putstr_fd("Steps : ", 1);
		ft_putnbr_fd(g->player.move, 1);
		ft_putstr_fd("\n", 1);
		g->tmp_press = g->player.move;
	}
	ft_display_imgs(g);
	return (0);
}
