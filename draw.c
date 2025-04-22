/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:03:00 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/22 18:02:16 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "miniRT.h"

/*int	hit_sphere(t_sphere s, t_ray r)
{
	t_vec3 oc = vec3_sub(r.origin, s.center);
	double a = vec3_dot(r.direction, r.direction);
	double b = 2.0 * vec3_dot(oc, r.direction);
	double c = vec3_dot(oc, oc) - s.radus * s.radus;
	double discriminant = b * b - 4 * a * c;
	return (discriminant >= 0);
}
t_ray	create_ray_camera(double u, double v, t_miniRT *minirt)
{
	double	px;
	double	py;
	double	pz;
	t_ray	ray;
	t_vec3	dir;
	px = (u - 0.5) * VIEWPORT_SIZE;
	py = (v - 0.5) * VIEWPORT_SIZE;
	pz = -FOCAL_LENGTH;
	
	ray.origin = vec3(0, 0, 0);
	dir = vec3_add(
		vec3_add(
			vec3_scale(minirt->camera.right, px),
			vec3_scale(minirt->camera.up, py)
		),
		vec3_scale(minirt->camera.forward, -FOCAL_LENGTH)
	);
	dir = vec3_normalize(dir);
	ray.direction = dir;
	return (ray);
}

void	check_colision(t_ray ray, t_miniRT *minirt, int x, int y)
{
	t_sphere sphere;

	sphere.center = vec3(0, 0, -10);
	sphere.radus = 2;

	if (hit_sphere(sphere, ray))
		my_mlx_pixel_put(&minirt->img, x, y, 0x00FF00);
	else
		my_mlx_pixel_put(&minirt->img, x, y, 0xFFFFFF);
}

void	give_pixel(int x, int y, t_miniRT *minirt)
{
	double	u;
	double	v;
	t_ray	ray;

	u = (x + 0.5) / WIDTH;
	v = (y + 0.5) / HEIGHT;
	ray = create_ray_camera(u, v, minirt);
	check_colision(ray, minirt, x, y);
}

void    draw(t_miniRT *minirt)
{
	int	x;
	int y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			give_pixel(x, y, minirt);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(minirt->mlx_ptr, minirt->mlx_win, minirt->img.img, 0, 0);
	mlx_loop(minirt->mlx_ptr);
}*/

int hit_sphere(t_sphere s, t_ray r)
{
	t_vec3 oc = vec3_sub(r.origin, s.center);
	double a = vec3_dot(r.direction, r.direction);
	double b = 2.0 * vec3_dot(oc, r.direction);
	double c = vec3_dot(oc, oc) - s.radus * s.radus;
	double discriminant = b * b - 4 * a * c;
	return (discriminant >= 0);
}

t_ray create_ray_camera(double u, double v, t_miniRT *minirt)
{
	double px = (u - 0.5) * VIEWPORT_SIZE;
	double py = (v - 0.5) * VIEWPORT_SIZE;
	double pz = -FOCAL_LENGTH;

	t_ray ray;
	t_vec3 dir = vec3_add(
		vec3_add(
			vec3_scale(minirt->camera.right, px),
			vec3_scale(minirt->camera.up, py)
		),
		vec3_scale(minirt->camera.forward, pz)
	);
	ray.origin = minirt->camera.origin;
	ray.direction = vec3_normalize(dir);
	return (ray);
}

void check_colision(t_ray ray, t_miniRT *minirt, int x, int y)
{
	t_sphere sphere;
	sphere.center = vec3(0, 0, -10);
	sphere.radus = 2;

	if (hit_sphere(sphere, ray))
		my_mlx_pixel_put(&minirt->img, x, y, 0x00FF00);
	else
		my_mlx_pixel_put(&minirt->img, x, y, 0xFFFFFF);
}

void give_pixel(int x, int y, t_miniRT *minirt)
{
	double u = (x + 0.5) / WIDTH;
	double v = (y + 0.5) / HEIGHT;
	t_ray ray = create_ray_camera(u, v, minirt);
	check_colision(ray, minirt, x, y);
}

void draw(t_miniRT *minirt)
{
	int x;
	int	y;
	int step;
	step = 4;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			give_pixel(x, y, minirt);
		
			for (int dx = 0; dx < step; dx++)
				for (int dy = 0; dy < step; dy++)
					my_mlx_pixel_put(&minirt->img, x + dx, y + dy, minirt->img.addr[((y * WIDTH + x) * 4)]); // couleur copiée
		
			y += step;
		}
		x += step;
	}
	mlx_put_image_to_window(minirt->mlx_ptr, minirt->mlx_win, minirt->img.img, 0, 0);
}

void rotate_camera_y(t_camera *cam, double angle)
{
	t_vec3 f = cam->forward;
	double cos_a = cos(angle);
	double sin_a = sin(angle);

	cam->forward.x = f.x * cos_a + f.z * sin_a;
	cam->forward.z = -f.x * sin_a + f.z * cos_a;
	cam->forward = vec3_normalize(cam->forward);

	cam->right = vec3_normalize(vec3_cross(cam->forward, cam->up));
	cam->up = vec3_normalize(vec3_cross(cam->right, cam->forward));
}

void rotate_camera_x(t_camera *cam, double angle)
{
	t_vec3 f = cam->forward;
	double cos_a = cos(angle);
	double sin_a = sin(angle);

	cam->forward.y = f.y * cos_a - f.z * sin_a;
	cam->forward.z = f.y * sin_a + f.z * cos_a;
	cam->forward = vec3_normalize(cam->forward);

	cam->up = vec3_normalize(vec3_cross(cam->right, cam->forward));
	cam->right = vec3_normalize(vec3_cross(cam->forward, cam->up));
}

int mouse_move_handler(int x, int y, t_miniRT *minirt)
{
	static int prev_x = -1;
	static int prev_y = -1;

	if (prev_x != -1)
	{
		int dx = x - prev_x;
		int dy = y - prev_y;
		double sensitivity = 0.005;

		if (dx != 0)
			rotate_camera_y(&minirt->camera, dx * sensitivity);
		if (dy != 0)
			rotate_camera_x(&minirt->camera, dy * sensitivity);

		draw(minirt);
	}
	prev_x = x;
	prev_y = y;
	return (0);
}
