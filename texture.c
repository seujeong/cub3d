#include "cub3d.h"

static int	*load_image(t_game *game, char *path, t_img *img, int index)
{
	int		x;
	int		y;
	int		*result;

	if (!(img->img = mlx_xpm_file_to_image(game->mlx,
					path, &img->img_width, &img->img_height)))
		exit_error(game, 1, "ERROR\nwrong texture");
	game->config.tex[index].width = img->img_width;
	game->config.tex[index].height = img->img_height;
	img->data = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->size_l, &img->endian);
	result = (int *)malloc(sizeof(int) * (img->img_width * img->img_height));
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
		{
			result[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(game->mlx, img->img);
	return (result);
}

void		load_texture(t_game *game)
{
	int		index;
	t_img	img;

	index = 0;
	while (index++ < TEXTURES)
	{
		game->config.tex[index].texture =
			load_image(game, game->config.tex[index].tex_path, &img, index);
		free(game->config.tex[index].tex_path);
	}
}
