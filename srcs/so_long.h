/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:32:42 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/03/06 14:10:32 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> // GET RID OF THAT SHIT !!!!!
# include "../includes/libft/libft.h"
# include "../includes/mlx/mlx.h"
# include <fcntl.h>

/*****************************************************************/
/*							MACRO KEYS  					     */
/*****************************************************************/

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/*****************************************************************/
/*							ERROR MESSAGES					     */
/*****************************************************************/
# define GAME_TITLE "so_long"
# define ERR_BAD_ARG "Invalid number of arguments !\n"
# define ERR_PATH "The map does not exist ! Wrong file path\n"
# define ERR_BAD_EXT "Wrong extension file\n"
# define ERR_NBR_PLAYER1 "Only one player can be on the map\n"
# define ERR_NBR_PLAYER2 "Player is missing from the map\n"
# define ERR_NBR_EXIT1 "Only one exit allowed on the map\n"
# define ERR_NBR_EXIT2 "Map exit is missing\n"
# define ERR_MISSING_WALL "Walls missing from the map\n"
# define ERR_UKNOWN_CHAR_MAP "Unkown character in the map parsing\n"
# define ERR_INIT_IMG "Missing image\n"
# define ERR_PATH_FINDING "Game is not playable.\n"
# define ERR_MLX_INIT "mlx_init error\n"
# define ERR_MLX_WIN "mlx_new_window error\n"
# define ERR_COIN_INT_MAX "There are more than INT MAX coins\n"
# define ERR_MEMORY "No enough memory\n"
# define ERR_EMPTY_MAP "The map is empty\n"

/*****************************************************************/
/*							STRUCTS								 */
/*****************************************************************/

typedef struct s_checkmap
{
	int	nbr_coin;
	int	nbr_player;
	int	nbr_exit;
	int	exit_x;
	int	exit_y;
	int	total_obj;
}	t_checkmap;

typedef struct s_map
{
	char	**map;
	char	**cp_map;
	int		nl;
	int		lenline;
}	t_map;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		coin_count;
	int		move;
	char	char_staged;
}	t_player;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*player_exit;
	void	*coin;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		*argv;
	int			w_height;
	int			w_width;
	t_checkmap	check;
	t_map		map;
	t_player	player;
	t_img		img;
}	t_game;

// UTILS.C
void	ft_check_ber_ext(char *argv);
void    ft_error(int res, char *tab1, char **tab2, char *error);
void    ft_path_map(char *dir, char *argv, t_game *g);
void    ft_init_struct(t_game *g);
void	ft_free_tab(char *tab1, char **tab2);

// PARSING.C
void	ft_init_len_nl(t_game *g);
void	ft_parsing_map(t_game *g);

//MAP_UTILS.C
void	ft_check_map(t_game *g);

//PATH_FINDING.C
int		ft_path_finding(t_game *g, int y, int x);
void	ft_cp_map(t_game *g);

//MLX_UTILS.C
int	red_cross(t_game *g);
int	key_pressed(int keycode, t_game *g);

// MOVEMENT.C
void	ft_movement(int key, t_game *g);

// IMG.C
void	ft_init_img(t_game *g);
void	ft_clear_imgs(t_game *g);
void	ft_display_imgs(t_game *g);
void	ft_put_img_win(t_game *g, int x, int y, char c);
#endif
