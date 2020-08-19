#include "cub3d.h"

t_env	*init_frame(t_env *env);

// KEY_CODE_PART
//		|
//		|
//		|
//		|
//		|
//		|
//		|
//		v

void	move_left(t_env *env)
{
	if (env->mv.rot_left == 1)
	{
		env->mv.old_dir_x = env->rc.player.dir_x;
		env->rc.player.dir_x = env->rc.player.dir_x * cos(-env->mv.speed_rot) - env->rc.player.dir_y * sin(-env->mv.speed_rot);
		env->rc.player.dir_y = env->mv.old_dir_x * sin(-env->mv.speed_rot) + env->rc.player.dir_y * cos(-env->mv.speed_rot);
		env->mv.old_plan_x = env->rc.planX;
		env->rc.planX = env->rc.planX * cos(-env->mv.speed_rot) - env->rc.planY * sin(-env->mv.speed_rot);
		env->rc.planY = env->mv.old_plan_x * sin(-env->mv.speed_rot) + env->rc.planY * cos(-env->mv.speed_rot);
	}
	if (env->mv.left == 1)
	{
		if (env->map.map[(int)(env->rc.player.position_y - env->rc.planY * 0.06)][(int)(env->rc.player.position_x)] != '1' && env->map.map[(int)(env->rc.player.position_y - env->rc.planY * 0.06)][(int)(env->rc.player.position_x)] != '2')
			env->rc.player.position_y -= env->rc.planY * 0.06;
		if (env->map.map[(int)(env->rc.player.position_y)][(int)(env->rc.player.position_x - env->rc.planX * 0.06)] != '1' && env->map.map[(int)(env->rc.player.position_y)][(int)(env->rc.player.position_x - env->rc.planX * 0.06)] != '2')
			env->rc.player.position_x -= env->rc.planX * 0.06;
	}
}

void	move_right(t_env *env)
{
	if (env->mv.rot_right == 1)
	{
		env->mv.old_dir_x = env->rc.player.dir_x;
		env->rc.player.dir_x = env->rc.player.dir_x * cos(env->mv.speed_rot) - env->rc.player.dir_y * sin(env->mv.speed_rot);
		env->rc.player.dir_y = env->mv.old_dir_x * sin(env->mv.speed_rot) + env->rc.player.dir_y * cos(env->mv.speed_rot);
		env->mv.old_plan_x = env->rc.planX;
		env->rc.planX = env->rc.planX * cos(env->mv.speed_rot) - env->rc.planY * sin(env->mv.speed_rot);
		env->rc.planY = env->mv.old_plan_x * sin(env->mv.speed_rot) + env->rc.planY * cos(env->mv.speed_rot);
	}
	if (env->mv.right == 1)
	{
		if (env->map.map[(int)(env->rc.player.position_y)][(int)(env->rc.planX * 0.06 + env->rc.player.position_x)] != '1' && env->map.map[(int)(env->rc.player.position_y)][(int)(env->rc.planX * 0.06 + env->rc.player.position_x)] != '2')
			env->rc.player.position_x += env->rc.planX * 0.06;
		if (env->map.map[(int)(env->rc.player.position_y + env->rc.planY * 0.06)][(int)(env->rc.player.position_x)] != '1' && env->map.map[(int)(env->rc.player.position_y + env->rc.planY * 0.06)][(int)(env->rc.player.position_x)] != '2')
			env->rc.player.position_y += env->rc.planY * 0.06;
	}
}

void	move_down(t_env *env)
{
	if (env->mv.down == 1)
	{
		if (env->map.map[(int)(env->rc.player.position_y)][(int)(env->rc.player.position_x - env->rc.player.dir_x * 0.06)] != '1' && env->map.map[(int)(env->rc.player.position_y)][(int)(env->rc.player.position_x - env->rc.player.dir_x * 0.06)] != '2')
			env->rc.player.position_x -= env->rc.player.dir_x * 0.06;
		if (env->map.map[(int)(env->rc.player.position_y - env->rc.player.dir_y * 0.06)][(int)(env->rc.player.position_x)] != '1' && env->map.map[(int)(env->rc.player.position_y - env->rc.player.dir_y * 0.06)][(int)(env->rc.player.position_x)] != '2')
			env->rc.player.position_y -= env->rc.player.dir_y * 0.06;
	}
}

void	move_up(t_env *env)
{
	if (env->mv.up == 1)
	{
		if (env->map.map[(int)(env->rc.player.position_y)][(int)(env->rc.player.position_x + env->rc.player.dir_x * 0.06)] != '1' && env->map.map[(int)(env->rc.player.position_y)][(int)(env->rc.player.position_x + env->rc.player.dir_x * 0.06)] != '2')
			env->rc.player.position_x += env->rc.player.dir_x * 0.06;
		if (env->map.map[(int)(env->rc.player.position_y + env->rc.player.dir_y * 0.06)][(int)(env->rc.player.position_x)] != '1' && env->map.map[(int)(env->rc.player.position_y + env->rc.player.dir_y * 0.06)][(int)(env->rc.player.position_x)] != '2')
			env->rc.player.position_y += env->rc.player.dir_y * 0.06;
	}
}

int	movement(t_env *env)
{
	env->mv.speed_rot = 0.06;
	move_up(env);
	move_down(env);
	move_right(env);
	move_left(env);
	init_frame(env);
	return (0);
}

int	key_exit(t_env *env)
{
	free(env->mlx_ptr);
	free(env->win_ptr);
	free(env->rc.north.img_ptr);
	free(env->rc.south.img_ptr);
	free(env->rc.east.img_ptr);
	free(env->rc.west.img_ptr);
	free(env->rc.render.dist_wall);
	exit(0);
	return (0);
}

int	key_release(int keycode, t_env *env)
{
	if (keycode == 119)
		env->mv.up = 0;
	if (keycode == 115)
		env->mv.down = 0;
	if (keycode == 100)
		env->mv.right = 0;
	if (keycode == 97)
		env->mv.left = 0;
	if (keycode == 65363)
		env->mv.rot_right = 0;
	if (keycode == 65361)
		env->mv.rot_left = 0;
	if (keycode == 65307)
		key_exit(env);
	return (0);
}

int	key_press(int keycode, t_env *env)
{
	if (keycode == 119)
		env->mv.up = 1;
	if (keycode == 115)
		env->mv.down = 1;
	if (keycode == 100)
		env->mv.right = 1;
	if (keycode == 97)
		env->mv.left = 1;
	if (keycode == 65363)
		env->mv.rot_right = 1;
	if (keycode == 65361)
		env->mv.rot_left = 1;
	return (0);
}

//		A
//		|
//		|
//		|
//		|
//		|
// KEY_CODE_PART
//
// SECOND PART
//		|
//		|
//		|
//		|
//		|
//		|
//	   \|/
//		v

t_texture	texture_wall(t_env *env)
{
	if (env->rc.side == 0 && env->rc.ray_x > 0)
		return (env->rc.east);
	else if (env->rc.side == 0 && env->rc.ray_x < 0)
		return (env->rc.west);
	else if (env->rc.side == 1 && env->rc.ray_y > 0)
		return (env->rc.south);
	else
		return (env->rc.north);
}

void	set_texture(t_env *env, int x)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			y;
	t_texture	tex_wall;

	tex_wall = texture_wall(env);
	if (env->rc.side == 0)
		wall_x = env->rc.player.position_y + env->rc.perp_wall_dist * env->rc.ray_y;
	else
		wall_x = env->rc.player.position_x + env->rc.perp_wall_dist * env->rc.ray_x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)tex_wall.width;
	y = env->rc.draw_start;
	while (y++ < env->rc.draw_end)
	{
		tex_y = (y - env->height_screen / 2 + env->rc.hauteur_line / 2) * tex_wall.height / env->rc.hauteur_line;
		if (tex_y < 0)
			return ;
		env->get_data[x + y * (env->size_line / 4)] = tex_wall.get_data[tex_x + tex_y * tex_wall.width];
	}
}

void	raycast_columns(t_env *env, int x, int y)
{
	env->rc.hauteur_line = (env->height_screen / env->rc.perp_wall_dist);
	env->rc.draw_start = -env->rc.hauteur_line / 2 + env->height_screen / 2;
	env->rc.draw_end = env->rc.hauteur_line / 2 + env->height_screen / 2;
	if (env->rc.draw_start < 0)
			env->rc.draw_start = 0;
	if (env->rc.draw_end >= env->height_screen)
		env->rc.draw_end = env->height_screen - 1;
	set_texture(env, x);
	y = 0;
	if (env->rc.draw_end < 0)
		env->rc.draw_end = env->height_screen;
	y = env->rc.draw_end;
	while (y < env->height_screen)
	{
		env->get_data[x + y * (env->size_line / 4)] = env->rc.color.floor;
		env->get_data[x + (env->height_screen - y - 1) * (env->size_line / 4)] = env->rc.color.roof;
		y++;
	}
}

void	init_color_wall(t_env *env)
{
	env->rc.color.north = 1644825;
	env->rc.color.south = 16718107;
	env->rc.color.east = 1654015;
	env->rc.color.west = 16727070;
}

void	color_wall(t_env *env)
{
	init_color_wall(env);
	if (env->rc.side == 0 && env->rc.ray_x > 0)
		env->rc.color.wall = env->rc.color.north;
	else if (env->rc.side == 0 && env->rc.ray_x < 0)
		env->rc.color.wall = env->rc.color.south;
	else if (env->rc.side == 1 && env->rc.ray_y > 0)
		env->rc.color.wall = env->rc.color.east;
	else
		env->rc.color.wall = env->rc.color.west;
}

void	dda_algorithm(t_env *env)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (env->rc.side_dist_x < env->rc.side_dist_y)
		{
			env->rc.side_dist_x += env->rc.delta_x;
			env->rc.current_position_x += env->rc.step_x;
			env->rc.side = 0;
		}
		else
		{
			env->rc.side_dist_y += env->rc.delta_y;
			env->rc.current_position_y += env->rc.step_y;
			env->rc.side = 1;
		}
		if (env->map.map[env->rc.current_position_y][env->rc.current_position_x] == '1')
			hit = 1;
	}
}

void	step_raycasting(t_env *env)
{
	if (env->rc.ray_x < 0)
	{
		env->rc.step_x = -1;
		env->rc.side_dist_x = (env->rc.player.position_x - env->rc.current_position_x) * env->rc.delta_x;
	}
	else
	{
		env->rc.step_x = 1;
		env->rc.side_dist_x = (env->rc.current_position_x + 1 - env->rc.player.position_x) * env->rc.delta_x;
	}
	if (env->rc.ray_y < 0)
	{
		env->rc.step_y = -1;
		env->rc.side_dist_y = (env->rc.player.position_y - env->rc.current_position_y) * env->rc.delta_y;
	}
	else
	{
		env->rc.step_y = 1;
		env->rc.side_dist_y = (env->rc.current_position_y + 1 - env->rc.player.position_y) * env->rc.delta_y;
	}
}

void	init_raycasting(t_env *env, int x)
{
	env->rc.camera_in_x = 2 * x / (double)(env->width_screen) - 1;
	env->rc.ray_x = env->rc.player.dir_x + env->rc.planX * env->rc.camera_in_x;
	env->rc.ray_y = env->rc.player.dir_y + env->rc.planY * env->rc.camera_in_x;
	env->rc.delta_x = fabs(1 / env->rc.ray_x);
	env->rc.delta_y = fabs(1 / env->rc.ray_y);
	env->rc.current_position_x = (int)env->rc.player.position_x;
	env->rc.current_position_y = (int)env->rc.player.position_y;
}

void	raycasting(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < env->width_screen)
	{
		init_raycasting(env, x);
		step_raycasting(env);
		dda_algorithm(env);
		if (env->rc.side == 0)
			env->rc.perp_wall_dist = (env->rc.current_position_x - env->rc.player.position_x + (1 - env->rc.step_x) / 2) / env->rc.ray_x;
		else
			env->rc.perp_wall_dist = (env->rc.current_position_y - env->rc.player.position_y + (1 - env->rc.step_y) / 2) / env->rc.ray_y;
		//color_wall(env);
		raycast_columns(env, x, y);
		env->rc.render.dist_wall[x] = env->rc.perp_wall_dist;
		x++;
	}
}

void	free_sprite(t_env *env)
{
	if (env->rc.render.dist_wall)
	{
		free(env->rc.render.dist_wall);
		env->rc.render.dist_wall = NULL;
	}
}


void	get_color(t_env *env, int i)
{
	if (env->rc.render.tex_y > 0)
	{
		if (env->rc.sprite[i].get_data[env->rc.render.tex_x + env->rc.render.tex_y * env->rc.sprite[i].width] != 0)
			env->rc.sprite[i].color = env->rc.sprite[i].get_data[env->rc.render.tex_x + env->rc.render.tex_y * env->rc.sprite[i].width];
		else
			env->rc.sprite[i].color = 0xBFD195;
	}
}

void	last_render_sprite(t_env *env, int x, int i)
{
	int	y;
	int	d;

	y = env->rc.render.start_y;
	while (y < env->rc.render.end_y)
	{
		d = (y * 256 - env->height_screen * 128 + env->rc.render.height * 128);
		env->rc.render.tex_y = (d * env->rc.sprite[i].height / env->rc.render.height) / 256;
		get_color(env, i);
		if (env->rc.sprite[i].color != 0xBFD195 && env->rc.render.transform_y < env->rc.render.dist_wall[x])
		{
			if (x >= 0 && x < env->width_screen && y >= 0 && y < env->height_screen)
			{
				env->get_data[x + y * (env->size_line / 4)] = env->rc.sprite[i].color;
			}
		}
		y++;
	}
}

void	aux_render_sprite(t_env *env, int i)
{
	env->rc.render.x = env->rc.sprite[env->rc.sprite[i].order].coord_x - env->rc.player.position_x;
	env->rc.render.y = env->rc.sprite[env->rc.sprite[i].order].coord_y - env->rc.player.position_y;
	env->rc.render.inv_det = 1 / (env->rc.planX * env->rc.player.dir_y - env->rc.player.dir_x * env->rc.planY);
	env->rc.render.transform_x = env->rc.render.inv_det * (env->rc.player.dir_y * env->rc.render.x - env->rc.player.dir_x * env->rc.render.y);
	env->rc.render.transform_y = env->rc.render.inv_det * (-env->rc.planY * env->rc.render.x + env->rc.planX * env->rc.render.y);
	env->rc.render.screen_x = (int)((env->width_screen / 2) * (1 + env->rc.render.transform_x / env->rc.render.transform_y));
	env->rc.render.height = abs((int)(env->height_screen / env->rc.render.transform_y));
	env->rc.render.start_y = -env->rc.render.height / 2 + env->height_screen / 2;	
	if (env->rc.render.start_y < 0)
		env->rc.render.start_y = 0;
	env->rc.render.end_y = env->rc.render.height / 2 + env->height_screen / 2;
	if (env->rc.render.end_y >= env->height_screen)
		env->rc.render.end_y = env->height_screen - 1;
	env->rc.render.width = abs((int)(env->height_screen / env->rc.render.transform_y));
	env->rc.render.start_x = -env->rc.render.width / 2 + env->rc.render.screen_x;
	if (env->rc.render.start_x < 0)
		env->rc.render.start_x = 0;
	env->rc.render.end_x = env->rc.render.width / 2 + env->rc.render.screen_x;
	if (env->rc.render.end_x >= env->width_screen)
		env->rc.render.end_x = env->width_screen - 1;
}

void	render_sprite(t_env *env)
{
	int	i;
	int	x;

	i = 0;
	while (i < env->rc.nbr_sprites)
	{
		aux_render_sprite(env, i);
		x = env->rc.render.start_x;
		while (x < env->rc.render.end_x && x < env->width_screen)
		{
			env->rc.render.tex_x = (int)(256 * (x - (-env->rc.render.width / 2 + env->rc.render.screen_x)) * env->rc.sprite[i].width / env->rc.render.width) / 256;
			if (env->rc.render.transform_y > 0)
				last_render_sprite(env, x, i);
			x++;
		}
		i++;
	}
}

void	sort_sprite(t_env *env)
{
	int	i;
	int	swap;

	i = 0;
	while (i + 1 < env->rc.nbr_sprites)
	{
		if (env->rc.sprite[env->rc.sprite[i].order].distance < env->rc.sprite[env->rc.sprite[i + 1].order].distance)
		{
			swap = env->rc.sprite[i].order;
			env->rc.sprite[i].order = env->rc.sprite[i + 1].order;
			env->rc.sprite[i + 1].order = swap;
			sort_sprite(env);
		}
		i++;
	}
}

void	sprite_distance(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->rc.nbr_sprites)
	{
		env->rc.sprite[i].order = i;
		env->rc.sprite[env->rc.sprite[i].order].distance = pow(env->rc.player.position_x - env->rc.sprite[env->rc.sprite[i].order].coord_x, 2) + pow(env->rc.player.position_y - env->rc.sprite[env->rc.sprite[i].order].coord_y, 2);
		i++;
	}
}

void	ray_sprite(t_env *env)
{
	sprite_distance(env);
	sort_sprite(env);
	render_sprite(env);
	free_sprite(env);
}

t_env	*init_frame(t_env *env)
{
	env->new_image = mlx_new_image(env->mlx_ptr, env->width_screen, env->height_screen);
	env->get_data = (int *)mlx_get_data_addr(env->new_image, &env->bits_per_pixel, &env->size_line, &env->endian);
	if (!(env->rc.render.dist_wall = ft_calloc(sizeof(double), env->width_screen)))
	{
		printf("Error malloc\n");
		exit(0);
	}
	raycasting(env);
	ray_sprite(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->new_image, 0, 0);
	mlx_do_sync(env->mlx_ptr);
	mlx_destroy_image(env->mlx_ptr, env->new_image);
	return (env);
}

t_env	*set_sprite(t_env *env)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < 11)
	{
		x = 0;
		while (x < 16)
		{
			if (env->map.map[y][x] == '2')
			{
				env->rc.sprite[i].coord_x = x + 0.5;
				env->rc.sprite[i].coord_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	return (env);
}

t_env	*pop_sprite(char *root_sprite, t_env *env, int i)
{
	if (!(env->rc.sprite[i].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, root_sprite, &env->rc.sprite[i].width, &env->rc.sprite[i].height)))
		printf("Something wrong in sprite\n");
	if (!(env->rc.sprite[i].get_data = (int *)mlx_get_data_addr(env->rc.sprite[i].img_ptr, &env->rc.sprite[i].bits_per_pixel, &env->rc.sprite[i].size_line, &env->rc.sprite[i].endian)))
		printf("Something wrong in sprite\n");
	return (env);
}

t_texture	pop_texture(char *root_texture, t_env *env)
{
	t_texture	texture;

	if (!(texture.img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, root_texture, &texture.width, &texture.height)))
		printf("Something wrong in texture\n");
	if (!(texture.get_data = (int *)mlx_get_data_addr(texture.img_ptr, &texture.bits_per_pixel, &texture.size_line, &texture.endian)))
		printf("Something wrong in texture\n");
	return (texture);
}

t_env	*init_textures(t_env *env)
{
	int	i;

	env->rc.north = pop_texture("textures/texture_rick_morty_1.xpm", env);
	env->rc.south = pop_texture("textures/texture_rick_morty_2.xpm", env);
	env->rc.east = pop_texture("textures/texture_rick_morty_3.xpm", env);
	env->rc.west = pop_texture("textures/texture_rick_morty_4.xpm", env);
	i = -1;
	while (++i < env->rc.nbr_sprites)
		env = pop_sprite("textures/rick.xpm", env, i);
	return (env);
}

int		open_app(t_env *env)
{
	if (!(env->mlx_ptr = mlx_init())) // Initialize the mlx server
	{
		free(env);
		exit(0);
		return (0);
	}
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, env->width_screen, env->height_screen, "Cub3d"))) // Initialize the window
	{
		free(env->mlx_ptr); // If window get wrong we gotta get free the mlx server pointer
		free(env);
		exit(0);
		return (0);
	}
	env = init_textures(env); // Preparing textures
	env = set_sprite(env);
	env = init_frame(env);
	mlx_hook(env->win_ptr, 2, 1, &key_press, env);
	mlx_hook(env->win_ptr, 3, 2, &key_release, env);
	mlx_hook(env->win_ptr, 33, 0, &key_exit, env);
	mlx_loop_hook(env->mlx_ptr, &movement, env);
	mlx_loop(env->mlx_ptr); // Keep the window open
	return (0);
}

//		A
//	   /|\
//		|
//		|
//		|
//		|
//		|
// SECOND PART
//
// FIRST PART
//		|
//		|
//		|
//		|
//		|
//	   \|/
//	    v

t_env	*orientation(t_env *env)
{
	if (env->rc.player.orientation_chr == 'N')
	{
		env->rc.player.dir_x = 0;
		env->rc.player.dir_y = -1;
	}
	else if (env->rc.player.orientation_chr == 'S')
	{
		env->rc.player.dir_x = 0;
		env->rc.player.dir_y = 1;
	}
	else if (env->rc.player.orientation_chr == 'W')
	{
		env->rc.player.dir_x = -1;
		env->rc.player.dir_y = 0;
	}
	else if (env->rc.player.orientation_chr == 'E')
	{
		env->rc.player.dir_x = 1;
		env->rc.player.dir_y = 0;
	}	
	env->rc.planX = -0.66 * env->rc.player.dir_y;
	env->rc.planY = 0.66 * env->rc.player.dir_x;
	return (env);
}

t_env	*init_position_player(t_env *env)
{
	// 0.5 is a constant
	env->rc.player.position_x = 1 + 0.5; // Position in x where 'E' is |       x  y
	env->rc.player.position_y = 2 + 0.5; // Position in y where 'E' is | ---> (2, 5) == 'E'
	env->rc.player.orientation_chr = 'E'; // If you change the orientation character in the map you gotta change this part
	return (env);
}

t_env	*init_sprite(t_env *env)
{
	env->rc.nbr_sprites = 4;
	if (!(env->rc.sprite = (t_sprite *)ft_calloc(sizeof(t_sprite), env->rc.nbr_sprites)))
		exit(0);
	return (env);
}

t_env	*init_main_colors(t_env *env)
{
	// If you wanna see different colors both in the roof and the floor you can change this
	env->rc.color.roof = 0;
	env->rc.color.floor = 1095719;
	return (env);
}

t_env	*init_resolution(t_env *env)
{
	env->width_screen = 800; // WIDTH RESOLUTION
	env->height_screen = 600; // HEIGHT RESOLUTION
	return (env);
}

t_env	*init_map(t_env *env, char map[11][16])
{
	int i;
	int j;

	i = 0;

	// Copy the map to the structure

	while (i < 11)
	{
		j = 0;
		while (j < 16)
		{
			env->map.map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	env->rc.mapX = 16; // Save the map width
	env->rc.mapY = 11; // Save the map height
	return (env);
}

//		A
//	   /|\
//		|
//		|
//		|
//		|
//		|
// FIRST PART

int		main(void)
{
	t_env	*env;
	char map[11][16] = {
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', 'E', '0', '0', '2', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '0', '0', '1'},
		{'1', '0', '0', '1', '1', '1', '0', '0', '0', '1', '0', '1', '1', '0', '2', '1'},
		{'1', '0', '0', '1', ' ', '1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '1', ' ', '1', '0', '0', '0', '1', '1', '1', '1', '0', '0', '1'},
		{'1', '2', '0', '1', ' ', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '1', ' ', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', ' ', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};

	// START FIRST PART

	env = (t_env *)malloc(sizeof(t_env)); // Allocate memory for the main structure
	env = init_map(env, map); // Initialize the map
	env = init_resolution(env); // Initialize the screen resolution
	env = init_main_colors(env); // Initialize the roof and floor colors
	env = init_sprite(env); // Allocate memory for sprites
	env = init_position_player(env); // Manually we ubicate where the player starts
	env = orientation(env); // It returns us the planX and planY and these are gonna help us to resolve the dda algorithm
	
	// END FIRST PART AND START SECOND PART
	
	open_app(env); // Start the app
	return (0);
}
