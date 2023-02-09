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
	}
	else
		ft_error(-1, NULL, NULL, ERR_BAD_ARG);
	return (0);
}
