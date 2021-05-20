#include "cub3d.h"

int		exit_error(t_game *game, int code, char *str)
{
	write(1, str, ft_strlen(str));
	exit(code);
	free_machine(game);
	return (code);
}

void	cast_rays(t_game *game)
{
	t_ray		ray[game->config.width];
	int			index;
	double		rayangle;

	rayangle = game->player.rotationangle - (game->config.fov / 2);
	index = -1;
	while (++index < game->config.width)
	{
		init_sprite(&ray[index].sprite);
		cast_ray(game, &ray[index], rayangle);
		render_stripe(game, game->config, ray, index);
		render_sprite(game, game->config, &ray[index], index);
		rayangle += game->config.fov / game->config.width;
	}
}

int		main_loop(t_game *game)
{
	move_player(game);
	render_ceiling(game);
	render_floor(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_game game;

	if (!(argc == 2 || (argc == 3 && !ft_strncmp(argv[2], "--save", 6))))
		return (exit_error(&game, 1, "ERROR\nargument error"));
	init_player(&game);
	init_config(&game);
	if (!parse_config(&game, &game.config, argv[1]))
		return (exit_error(&game, 1, "ERROR\nparsing map error"));
	if (!check_all_type(&game))
		return (exit_error(&game, 1, "ERROR\ntype error"));
	if (!check_map_validation(&game, game.config))
		return (exit_error(&game, 1, "ERROR\ninvalid map"));
	init_game(&game);
	load_texture(&game);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		return (screenshot(&game));
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
