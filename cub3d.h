#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_colors
{
	int	roof;
	int	floor;
	int	north;
	int	south;
	int	east;
	int	west;
	int	wall;
}				t_colors;

typedef struct	s_movement
{
	int		up;
	int		down;
	int		right;
	int		left;
	int		rot_right;
	int		rot_left;
	double	old_dir_x;
	double	old_plan_x;
	double	speed_rot;
}				t_movement;

typedef struct	s_rendering
{
	double	*dist_wall; // Distance from the wall to the player plan
}				t_rendering;

typedef struct	s_player
{
	double	position_x; // player position in x
	double	position_y; // player position in y
	double	dir_x;
	double	dir_y;
	char	orientation_chr; // Identifier = 'N' 'S' 'E' 'W' 
}				t_player;

typedef struct	s_texture
{
	void	*img_ptr; // Pointer to texture
	int		bits_per_pixel; // Default variable
	int		size_line; // Default variable
	int		endian; // Default variable
	int		*get_data; // Image data
	int		width;	// Default variable
	int		height; // Default variable
}				t_texture;

typedef struct	s_raycasting
{
	t_texture	north; // North texture
	t_texture	south; // South texture
	t_texture	east; // East texture
	t_texture	west; // West texture
	t_colors	color; // Variable color type = colors
	t_player	player; // Variable player type = structure
	t_rendering	render; // Variable render type = rendering
	int			mapX; // Map width
	int			mapY; // Map height
	double		planX; // Player plan in x
	double		planY; // PLayer plan in y
	double		camera_in_x;
	double		ray_x;
	double		ray_y;
	int			current_position_x;
	int			current_position_y;
	double		delta_x;
	double		delta_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int 		hauteur_line;
	int			draw_start;
	int			draw_end;
	// I know, this fuck*** structure is getting complicated
}				t_raycasting;

typedef struct	s_map
{
	char map[11][16]; // Map
}				t_map;

typedef struct	s_env
{
	void			*mlx_ptr; // Server pointer to start window
	void			*win_ptr; // Pointer to window
	void			*new_image; // Poniter to a new image/frame
	int				bits_per_pixel; // Default variable
	int				size_line; // Default variable
	int				endian; // Deafault variable
	int				width; // Default variable
	int				height; // Default variable
	int				*get_data; // Window data
	int				width_screen; // Screen resolution 
	int				height_screen; // Screen resolution
	t_map			map; // Variable type map
	t_raycasting	rc; // Variable type raycasting
	t_movement		mv; // Variable type movement :v
}				t_env;

#endif