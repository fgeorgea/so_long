/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:53:46 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/02/09 15:53:49 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	red_cross(t_game *g)
{
	ft_destroy_all_img(g);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_pressed(int keycode, t_game *g)
{
	char	*move;

	mlx_clear_window(g->mlx, g->mlx_win);
	ft_movement(keycode, g);
	move = ft_itoa(g->player.move);
	if (!move)
	{
		ft_destroy_all_img(g);
		ft_error(-1, NULL, g->map.map, ERR_MEMORY);
	}
	if (g->player.move < 2)
		ft_putstr_fd("Step : ", 1);
	else
		ft_putstr_fd("Steps : ", 1);
	ft_putstr_fd(move, 1);
	write(1, "\n", 1);
	free(move);
	ft_print_infos(g);
	ft_put_img_map(g);
	return (0);
}
