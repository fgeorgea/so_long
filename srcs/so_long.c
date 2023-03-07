/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:28:46 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/07 14:24:56 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_parse_arg(t_game *g, char *argv)
{
	if (ft_strncmp("maps/", argv, 5) == 0)
	{
		g->argv = argv;
		ft_check_ber_ext(g->argv);
	}
	else
	{
		ft_error(-1, NULL, NULL, ERR_PATH);
	}
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc == 2)
	{
		ft_parse_arg(&g, argv[1]);
		ft_init_struct(&g);
		ft_display_imgs(&g);
		mlx_hook(g.mlx_win, 17, 0, &red_cross, &g);
		mlx_hook(g.mlx_win, KEY_PRESS, 0, &key_pressed, &g);
		mlx_loop(g.mlx);
		ft_clear_imgs(&g);
		ft_free_tab(NULL, g.map.map);
	}
	else
		ft_error(-1, NULL, NULL, ERR_BAD_ARG);
	return (0);
}
