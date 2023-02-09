/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:59:48 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/02/09 14:02:39 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int res, char *tab1, char **tab2, char *error)
{
	if (res < 0)
	{
		if (tab1)
				//free tab1
		if (tab2)
				//free tab2
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(error, 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_ber_ext(char *argv)
{
	int	file_type_pos;

	file_type_pos = ft_strlen(argv) - 4;
	if(ft_strncmp(&argv[file_type_pos], ".ber", 4) != 0)
	ft_error(-1, NULL, NULL, ERR_BAD_EXT);
}

void	ft_init_struct(t_game *g)
{
	ft_init_lenline_nl(g);
	g->w_height = g->map.nl * 32;
	g->w_width = (g->map.lenline - 1) * 32;
	g->mlx = mlx_init();
	if (!g->mlx)
		ft_error(-1, NULL, NULL, ERR_MLX_INIT);
	g->mlx_win = \
	mlx_new_window(g->mlx, g->w_width, g->w_height + 20, GAME_TITLE);
	if (!g->mlx_win)
		ft_error(-1, NULL, NULL, ERR_MLX_WIN);
	g->player.pos_x = 0;
	g->player.pos_y = 0;
	g->player.coin_collected = 0;
	g->player.move = 0;
	ft_parsing_map(g);
	g->check.nbr_coin = 0;
	g->check.nbr_player = 0;
	g->check.nbr_exit = 0;
	g->check.exit_pos_x = 0;
	g->check.exit_pos_y = 0;
	ft_check_map(g);
	ft_init_img(g);
}
