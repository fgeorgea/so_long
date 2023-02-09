/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps_coins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:54:11 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/02/09 15:54:12 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_step1(t_game *g, int start, char *move)
{
	if (g->w_width <= 288)
	{
		mlx_string_put(g->mlx, g->mlx_win, start, 15, 0xFFFFFF, "S:");
		mlx_string_put(g->mlx, g->mlx_win, start + 15, 15, 0x00FF00, move);
	}
	else
	{
		if (g->player.move <= 1)
		{
			mlx_string_put(g->mlx, g->mlx_win, start, 15, 0xFFFFFF, "Step :");
			mlx_string_put(g->mlx, g->mlx_win, start + 50, 15, 0x00FF00, move);
		}
		else
		{
			mlx_string_put(g->mlx, g->mlx_win, start, 15, 0xFFFFFF, "Steps :");
			mlx_string_put(g->mlx, g->mlx_win, start + 50, 15, 0x00FF00, move);
		}
	}
}

static void	ft_print_step(t_game *g, int start)
{
	char	*move;

	move = ft_itoa(g->player.move);
	if (!move)
	{
		ft_destroy_all_img(g);
		ft_error(-1, NULL, g->map.map, ERR_MEMORY);
	}
	ft_print_step1(g, start, move);
	free(move);
}

static void	ft_print_coin_collected1(t_game *g, int mid, char *coins)
{
	if (g->w_width <= 288)
	{
		mlx_string_put(g->mlx, g->mlx_win, g->w_width / 2, 15, 0xFFFFFF, "C:");
		mlx_string_put(g->mlx, g->mlx_win,
			(g->w_width / 2) + 15, 15, 0xFFFF00, coins);
	}
	else
	{
		if (g->player.coin_collected <= 1)
		{
			mlx_string_put(g->mlx, g->mlx_win,
				mid, 15, 0xFFFFFF, "Coin collected :");
			mlx_string_put(g->mlx, g->mlx_win, mid + 120, 15, 0xFFFF00, coins);
		}
		else
		{
			mlx_string_put(g->mlx, g->mlx_win,
				mid, 15, 0xFFFFFF, "Coins collected :");
			mlx_string_put(g->mlx, g->mlx_win, mid + 125, 15, 0xFFFF00, coins);
		}
	}
}

static void	ft_print_coin_collected(t_game *g, int mid)
{
	char	*coins;

	coins = ft_itoa(g->player.coin_collected);
	if (!coins)
	{
		ft_destroy_all_img(g);
		ft_error(-1, NULL, g->map.map, ERR_MEMORY);
	}
	ft_print_coin_collected1(g, mid, coins);
	free(coins);
}

void	ft_print_infos(t_game *g)
{
	int	start;
	int	mid;

	start = (g->w_width / g->w_width) + 4;
	mid = (g->w_width / 2) - 60;
	ft_print_step(g, start);
	ft_print_coin_collected(g, mid);
}
