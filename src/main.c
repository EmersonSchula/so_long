/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:45:22 by eschula           #+#    #+#             */
/*   Updated: 2025/03/11 12:47:38 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		handle_error(E_INVALID_ARGS);
	ft_validate_file(argv[1]);
	game = get_game();
	ft_init_game_struct(game);
	ft_get_map(game, argv[1]);
	ft_validate_map(game);
	ft_validate_exit(&(game->flood), game->map.ppos.x, game->map.ppos.y);
	if (game->flood.collect != 0 || game->flood.exit != 0)
		handle_error(E_MAP_IMPOSSIBLE_FINISH);
	ft_start_mlx(game);
	mlx_loop(get_mlx()->mlx_ptr);
	handle_error(EXIT_SUCCESS);
}
