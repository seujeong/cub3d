/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:28:19 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:00:17 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "inits/init.h"
# include "utils/utils.h"
# include "base.h"

int		main(int ac, char **av);
int		main_loop(t_info *info);
void	exit_cub3d(t_info *info, int check);
int		exit_msg(t_info *info, char const *msg);
int		key_press(int keycode, t_info *info);
int		key_release(int keycode, t_info *info);
int		exit_hook(t_info *info);
void	render(t_info *info);
void	render_fc(t_info *info);
void	render_wall(t_info *info);
void	render_init(t_info *info, int x);
void	render_raydir(t_info *info);
void	render_hit(t_info *info);
int		render_texnum(t_info *info);
int		render_len(t_info *info, int texnum);
void	render_draw(t_info *info, int texnum, int tex_x, int x);
void	render_sprite(t_info *info);
void	init_sprite(t_info *info, t_sprite	*s);
void	draw_sprite(t_info *info, int stripe, t_sprite *s);
int		save(t_info *info);
void	move(t_info *info);
void	move_lr(t_info *info);
void	move_ad(t_info *info);
void	move_ws(t_info *info);

#endif
