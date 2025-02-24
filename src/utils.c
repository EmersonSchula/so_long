
#include "so_long.h"

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
