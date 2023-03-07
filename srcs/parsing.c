/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:30:58 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/07 16:49:08 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_len_nl(t_game *g)
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
		str = get_next_line(fd);
		if ((str && str[0] == '\n') || (empty == 1 && !str))
			ft_error(-1, NULL, NULL, ERR_EMPTY_MAP);
		empty = 0;
		if (g->map.lenline == 0)
			g->map.lenline = ft_strlen(str);
		if (!str)
			break ;
		g->map.nl++;
		free(str);
	}
	ft_check_map_size(g->map.nl);
	close(fd);
}

static void	ft_parsing_map_norm(int fd, t_game *g)
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
		g->map.map[i] = malloc(sizeof(char) * (g->map.lenline + 1));
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

	g->map.map = malloc(sizeof(char *) * (g->map.nl + 1));
	if (!g->map.map)
		return ;
	g->map.map[g->map.nl] = NULL;
	fd = open(g->argv, O_RDONLY);
	if (fd < 0)
		ft_error(fd, NULL, NULL, ERR_PATH);
	ft_parsing_map_norm(fd, g);
	close(fd);
}

void	ft_check_map_size(int size)
{
	if (size > 11)
		ft_error(-1, NULL, NULL, ERR_TOO_BIG);
	return ;
}
