
#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	// Verifica se o argumento do mapa foi fornecido corretamente
	if (argc != 2)
		handle_error(E_INVALID_ARGS);
	
	// Verifica se o arquivo tem a extensão .ber e pode ser lido
	ft_validate_file(argv[1]);
	
	// Ponteiro para a estrutura principal do jogo recebe um ponteiro global.
	game = get_game();
	
	// Inicializa a estrutura do jogo
	ft_init_game_struct(game);
	
	// Carrega o mapa na estrutura do jogo
	ft_get_map(game, argv[1]);
	
	// Valida se o mapa segue todas as regras
	ft_validate_map(game);
	
	// Verifica se há um caminho válido para todos os coletáveis e a saída
	ft_validate_exit(&(game->flood), game->map.ppos.x, game->map.ppos.y);
	if (game->flood.collect != 0 || game->flood.exit != 0)
		handle_error(E_MAP_IMPOSSIBLE_FINISH);
		
	// Inicia a MiniLibX e abre a janela do jogo
	ft_start_mlx(game);
	
	// Executa o loop principal do jogo
	mlx_loop(get_mlx()->mlx_ptr);
	
	// Finaliza o programa corretamente quando o jogo termina.
	handle_error(EXIT_SUCCESS);
}
