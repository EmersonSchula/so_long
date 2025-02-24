
#include "so_long_bonus.h"

t_game	*get_game(void)
{
	static t_game	game;

	return (&game);
}

t_mlx	*get_mlx(void)
{
	static t_mlx	mlx;

	return (&mlx);
}

void	get_map_lenght(t_map *map)
{
	map->x_len = ft_strlen(map->map[0]);
	map->y_len = 0;
	while (map->map[map->y_len])
		map->y_len++;
}

void	display_moves(t_game *game)
{
	static mlx_image_t	*move_img;
	char				*counter;

	if (move_img)
		mlx_delete_image(get_mlx()->mlx_ptr, move_img);
	counter = ft_itoa(game->steps);
	mlx_put_string(get_mlx()->mlx_ptr, "steps:", 5, 5);
	move_img = mlx_put_string(get_mlx()->mlx_ptr, counter, 70, 5);
	free(counter);
}
