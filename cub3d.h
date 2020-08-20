#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_colors
{
	int	roof; //	|
	int	floor; //	|
	int	north; //	| ----> They are the fuc**** colors, don't be dumb
	int	south; //	|
	int	east; //	|
	int	west; //	|
	int	wall; // Pixel-color
}				t_colors;

typedef struct	s_movement
{
	int		up; // Movement to north
	int		down; // Movement to south
	int		right; // Movement to east
	int		left; // Movement to west
	int		rot_right; // Rotation to east
	int		rot_left; // Rotation to west
	double	old_dir_x; // Old direction x
	double	old_plan_x; // Old x-plane
	double	speed_rot; // Rotation speed
}				t_movement;

typedef struct	s_sprite
{
	int		order; // Order of the sprites
	double	distance; // Distance from player position to the sprite position
	double	coord_x; // x-coordenate of the sprite
	double	coord_y; // y-coordenate of the sprite
	void	*img_ptr; // Identifier pointer to the screen
	int		*get_data; // Data int array of the screen
	int		bits_per_pixel; // Default variable
	int		size_line; // Default variable
	int		endian; // Default variable
	int		width; // Default variable
	int		height; // Default variable
	int		color; // Pixel-color
}				t_sprite;

// rendering structure is used for sprites

typedef struct	s_rendering
{
	double	x; // x-coordenate
	double	y; // y-coordenate
	double	inv_det; // Inverse determinant
	double	transform_x; // x-transformed
	double	transform_y; // y-transformed
	int		screen_x; // x-coordenate in space camera sprite
	int		start_x; // Calculate width on the sprite
	int		start_y; // Calculate highest pixel to draw in column
	int		end_x; // Calculate end of the width on the sprite
	int		end_y; // Calculate lowest pixel to draw in column
	int		tex_x; // x-coordenate to put on the screen
	int		tex_y; // y-coordenate to put on the screen
	int		height; // Hegiht of the sprite on the screen
	int		width; // Width of the screen on the screen
	double	*dist_wall; // Distance from the wall to the player plan
}				t_rendering;

typedef struct	s_player
{
	double	position_x; // Player position in x
	double	position_y; // Player position in y
	double	dir_x; // Initial direction vector x
	double	dir_y; // Initial direction vector y
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
	t_sprite	*sprite; // Pointer to the sprite structure
	t_player	player; // Variable player type = structure
	t_rendering	render; // Variable render type = rendering
	int			map_x; // jump to next map square, OR in x-direction, OR in y-direction
	int			map_y; // ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' '
	double		planX; // Camera plane in x for raycasting in 2D
	double		planY; // Camera plane in y for raycasting in 2D
	double		camera_in_x; // x-coordinate in camera space 
	double		ray_x; // Ray in x-coordinate
	double		ray_y; // Ray in y-coordinate
	double		delta_x; // Length of ray from one x/y-side to next x/y-side
	double		delta_y; // ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' 
	double		side_dist_x; // Length of ray from current position to next x/y-side
	double		side_dist_y; // ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' ' '
	double		perp_wall_dist; // Calculate distance projected on camera direction
	int			step_x; // x-step in the map
	int			step_y; // y-step in the map
	int			side; // Whether an x-side or y-side of a wall was hit in the variable "side"
	int 		line_height; // Calculate height of line to draw on screen
	int			draw_start; // Calculate the lowest pixel to draw the current column/stripe
	int			draw_end; // Calculate the highest pixel to draw the current column/stripe
	int			nbr_sprites; // Sprites number xd lmao
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
