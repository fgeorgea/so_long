/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:30:58 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/02/09 13:55:05 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_lenline_nl(t_game *g)
{
	char	*str;
	int		fd;
	int		empty;

	g->map.lenline = 0;
	g->map.nl = 0;
	fd = open(g->argv, O_RDONLY);
	if (fd < 0)
		ft_error(fd, NULL, NULL, ERR_PATH);
	empty = 1;
	while (1)
	{
		if (!str && empty == 1)
			ft_error(-1, NULL, NULL, ERR_EMPTY_MAP);
		empty = 0;
		if (g->map.lenline == 0)
			g->map.lenline = ft_strlen(str);
		if (!str)
			break ;
		g->map.nl++;
		free(str);
	}
	close(fd);
}

static void	ft_cut_parsing_map(int fd, t_game *g)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		j = -1;
		if (!str)
			break ;
		g->map.map[i] = malloc(sizeof(char) * g->map.lenline + 1);
		if (!g->map.map[i])
			return ;
		while (str[++j])
		{
			if (str[j] != '0' && str[j] != '1' && str[j] != 'P' && str[j] != 'C'
				&& str[j] != 'E' && str[j] != '\n')
				ft_error(-1, str, NULL, ERR_UKNOWN_CHAR_MAP);
			g->map.map[i][j] = str[j];
		}
		g->map.map[i][j] = '\0';
		i++;
		free(str);
	}
}

void	ft_parsing_map(t_game *g)
{
	int		fd;

	g->map.map = malloc(sizeof(char *) * g->map.nl + 1);
	if (!g->map.map)
		return ;
	g->map.map[g->map.nl] = NULL;
	fd = open(g->argv, O_RDONLY);
	if (fd < 0)
		ft_error(fd, NULL, NULL, ERR_PATH);
	ft_cut_parsing_map(fd, g);
	close(fd);
	if (g->argv_malloc == 1)
		ft_free_tab(g->argv, NULL);
}