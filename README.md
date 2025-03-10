# so_long

`so_long` is a simple game developed in C using the MLX42 library. The goal of the game is to collect all items and reach the exit of the map.

## Dependencies

- [MLX42](https://github.com/codam-coding-college/MLX42)
- [libft](https://github.com/42Paris/libft)

## Compilation and Execution

To compile and run the project, follow the steps below:

1. Clone the repository:
    ```sh
    git clone <https://github.com/EmersonSchula/so_long.git>
    cd <so_long>
    ```

2. Compile the project:
    ```sh
    make
    ```

3. Run the game:
    ```sh
    ./so_long maps/test.ber
    ```

## Project Structure

## Code Structure

- [src](http://_vscodecontentref_/1): Contains the source files of the project.
- [includes](http://_vscodecontentref_/2): Contains the header files.
- [libs](http://_vscodecontentref_/3): Contains the external libraries used in the project.
- [assets](http://_vscodecontentref_/4): Contains the image files used in the game.
- [maps](http://_vscodecontentref_/5): Contains the `.ber` map files.

## Game Controls

- `W`: Move up
- `A`: Move left
- `S`: Move down
- `D`: Move right

## Common Errors

- `E_INVALID_ARGS`: Invalid arguments provided.
- `E_INVALID_FILE`: Invalid file.
- `E_INVALID_MAP_NAME`: Invalid map name.
- `E_INVALID_MAP_CONTENT`: Invalid map content.
- `E_MAP_IMPOSSIBLE_FINISH`: Impossible to finish the map.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
