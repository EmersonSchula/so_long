
#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		handle_error(E_INVALID_ARGS);
	ft_validate_file(argv[1]);
	game = get_game();
	ft_get_map(game, argv[1]);
	ft_validate_map(game);
	ft_start_mlx(game);
	handle_error(EXIT_SUCCESS);
}
