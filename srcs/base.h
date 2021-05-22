/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:27:14 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:00:04 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include "../mlx/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>

# define X_KEY_PRESS	2
# define X_KEY_RELEASE	3
# define X_EXIT			17

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_ESC		53
# define KEY_LEFT		123
# define KEY_RIGHT		124

# define NO 			0
# define SO 			1
# define WE 			2
# define EA 			3
# define S 				4
# define F 				5
# define C 				6
# define R 				7
# define MAP 			8

# define FOV			0.8
# define MSPEED			0.1
# define RSPEED			0.1

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_key
{
	char			w;
	char			a;
	char			s;
	char			d;
	char			left;
	char			right;
	char			esc;
}					t_key;

typedef struct		s_map
{
	char			**data;
	int				width;
	int				height;
}					t_map;

typedef struct		s_parsetype
{
	int				check_exit;
	int				check;
	int				map;
	int				resolution_x;
	int				resolution_y;
}					t_ptype;

typedef struct		s_color
{
	int				c;
}					t_color;

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_floatxy
{
	float			x;
	float			y;
}					t_floatxy;

typedef struct		s_spos
{
	float			x;
	float			y;
	int				n;
}					t_spos;

typedef struct		s_sprite
{
	t_spos			*spos;
	int				snum;
	float			spritex;
	float			spritey;
	float			invdet;
	float			transformx;
	float			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				spritewidth;
	int				drawendx;
	int				drawstartx;
	int				drawendy;
	int				drawstarty;
	int				color;
}					t_sprite;

typedef struct		s_intxy
{
	int				x;
	int				y;
}					t_intxy;

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	t_ptype			ptype;
	t_key			key;
	t_img			img;
	t_img			tex[5];
	t_color			color[2];
	t_map			map;
	t_floatxy		dir;
	t_floatxy		ray;
	t_floatxy		plane;
	t_floatxy		pos;
	t_floatxy		sidedist;
	t_floatxy		deltadist;
	float			walldist;
	t_intxy			mapxy;
	t_intxy			step;
	int				drawstart;
	int				drawend;
	int				side;
	int				lineh;
	float			*buf;
	t_sprite		sprite;
}					t_info;

#endif
