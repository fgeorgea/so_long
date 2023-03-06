/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:54:05 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/01 11:53:35 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cp_map(t_game *g)
{
	int		i;
	int		j;

	g->map.cp_map = malloc(sizeof(char *) * g->map.nl + 1);
	if (!g->map.cp_map)
		return ;
	g->map.cp_map[g->map.nl] = NULL;
	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		g->map.cp_map[i] = malloc(sizeof(char) * g->map.lenline + 1);
		if (!g->map.cp_map[i])
			return ;
		while (g->map.map[i][++j])
			g->map.cp_map[i][j] = g->map.map[i][j];
		g->map.cp_map[i][j] = '\0';
	}
}

int	ft_path_finding(t_game *g, int y, int x)
{
	char	up;
	char	down;
	char	left;
	char	right;

	if (g->check.total_obj == 0)
		return (0);
	up = g->map.cp_map[y - 1][x];
	down = g->map.cp_map[y + 1][x];
	left = g->map.cp_map[y][x - 1];
	right = g->map.cp_map[y][x + 1];
	if (g->map.cp_map[y][x] == 'C' || g->map.cp_map[y][x] == 'E')
		g->check.total_obj--;
	g->map.cp_map[y][x] = '2';
	if (up != '1' && up != '2')
		ft_path_finding(g, y - 1, x);
	if (down != '1' && down != '2')
		ft_path_finding(g, y + 1, x);
	if (left != '1' && left != '2')
		ft_path_finding(g, y, x - 1);
	if (right != '1' && right != '2')
		ft_path_finding(g, y, x + 1);
	if (g->check.total_obj == 0)
		return (0);
	return (-1);
}
