/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:27:08 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:36:33 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../base.h"
# include "../main.h"

void	init(t_info *info, int flag, char *av);
void	parse_texture(t_info *info, int type, char *path);
void	parse_resolution(t_info *info, char **split);
void	parse_color(t_info *info, int typefc, char *word);
void	init_parse(t_info *info, char *av);
int		check_cub(char *av);
void	check_information(t_info *info, char *line);
int		check_type(char *line, t_info *info);
void	check_parse(t_info *info, int type);
void	check_map(t_info *info, int	x, int y);
int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
void	init_map(t_info *info, int fd, char *line, int *gnl_check);
void	map_parsing(t_info *info, int fd, char *line, int *gnl_check);
void	map_setup(t_info *info, int max_y, int max_x, t_list *lst);
int		init_player(t_info *info, t_floatxy pos);
void	init_sprite_pos(t_info *info);
void	init_struct(t_info *info);

#endif
