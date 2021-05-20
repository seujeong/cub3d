#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
//# include <unistd.h>
# include <math.h>
//# include "mlx.h"
# include "libft.h"

# define M_PI					3.1415926535897937

# define FALSE					0
# define TRUE					1
# define BUFFER_SIZE			16

# define KEY_1					18
# define KEY_2					19
# define KEY_3					20
# define KEY_4					21
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_R					15
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_I					34
# define KEY_O					31
# define KEY_P					35
# define KEY_J					38
# define KEY_K					40
# define KEY_L					37
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_UP 				126
# define KEY_DOWN				125
# define KEY_MINUS				27
# define KEY_PLUS				24

# define KEY_TAB				48
# define KEY_MAJ				257
# define KEY_ESC				53

# define NESW					"NESW"
# define MOVESPEED				2

# define SPRITE					2

# define FALSE					0
# define TRUE					1
# define BUFFER_SIZE			16

# define TEXTURES				5
# define TEX_NORTH				0
# define TEX_SOUTH				1
# define TEX_WEST				2
# define TEX_EAST				3
# define TEX_SPRITE				4

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_GAME_CLEAR		7
# define X_EVENT_KEY_EXIT		17

# define C_R					6
# define C_NO					0
# define C_SO					1
# define C_WE					2
# define C_EA					3
# define C_S					4
# define C_TUNA					5
# define C_LB					6
# define C_GC					7
# define C_F 					8
# define C_C					9
# define C_MAP					10

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_sprite
{
	int			content;
	t_pos		verhit;
	t_pos		horhit;
	t_pos		hit;
	t_pos		mappos;
	t_pos		mapcenter;
	double		angle;
	double		min_angle;
	double		max_angle;
	double		distance;
	double		height;
	int			tex_x;
}				t_sprite;

typedef struct	s_ray
{
	double		rayangle;
	double		distance;
	t_pos		wallhit;
	t_sprite	sprite;
	int			washitvertical;
	int			isup;
	int			isdown;
	int			isleft;
	int			isright;
	int			wallhitcontent;
}				t_ray;

typedef struct	s_tex
{
	char		*tex_path;
	int			*texture;
	double		width;
	double		height;
}				t_tex;

typedef struct	s_config
{
	int			width;
	int			height;
	int			rows;
	int			colums;
	double		tile;
	t_tex		tex[TEXTURES];
	int			floor_color;
	int			ceiling_color;
	char		**map;
	double		rotation_speed;
	double		updown_speed;
	double		move_speed;
	double		eyelevel;
	double		fov;
	int			t_num;
}				t_config;

typedef struct	s_player
{
	float		x;
	float		y;
	float		width;
	float		height;
	int			turndirection;
	int			walkdirection;
	int			walkdirection_lr;
	float		rotationangle;
	float		walkspeed;
	float		turnspeed;
	double		rotationspeed;
	double		eyelevel;
}				t_player;

typedef struct	s_game
{
	t_config	config;
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
}				t_game;

#endif
