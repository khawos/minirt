/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:03:00 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/23 07:18:15 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "miniRT.h"

int	hit_sphere(t_sphere s, t_ray r)
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
	(void)minirt;
	px = (u - 0.5) * VIEWPORT_SIZE;
	py = (v - 0.5) * VIEWPORT_SIZE;
	pz = -FOCAL_LENGTH;
	
	ray.origin = vec3(0, 0, 0);
	ray.direction = vec3_normalize(vec3(px, py ,pz));
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
	
	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			give_pixel(x, y, minirt);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(minirt->mlx_ptr, minirt->mlx_win, minirt->img.img, 0, 0);
	mlx_loop(minirt->mlx_ptr);
}