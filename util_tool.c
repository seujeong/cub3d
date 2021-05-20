#include "cub3d.h"

void	free_machine(t_game *game)
{
	int index;

	index = 0;
	while (index++ < game->config.rows)
	{
		if (game->config.map[index])
			free(game->config.map[index]);
	}
	free(game->config.map);
	index = 0;
	while (index++ < TEXTURES)
	{
		if (game->config.tex[index].texture)
			free(game->config.tex[index].texture);
	}
}

int		free_line(char *line, int ret)
{
	free(line);
	return (ret);
}

char	*update_temp(char *temp, char *line)
{
	char *temp2;
	char *temp3;

	temp2 = ft_strjoin(line, "\n");
	temp3 = ft_strjoin(temp, temp2);
	free(temp);
	free(temp2);
	temp = NULL;
	return (temp3);
}
