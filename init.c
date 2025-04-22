/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:54:28 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/22 17:34:24 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_camera(t_miniRT *minirt)
{
	minirt->camera.origin = vec3(0, 0, 0);
	minirt->camera.forward = vec3_normalize(vec3(0, 0, -1)); // regarde en Z-
	minirt->camera.right = vec3_normalize(vec3(1, 0, 0));    // droite
	minirt->camera.up = vec3_normalize(vec3(0, 1, 0));       // haut
}

void	init(t_miniRT *minirt)
{
	minirt->mlx_ptr = mlx_init();
	minirt->mlx_win = mlx_new_window(minirt->mlx_ptr, WIDTH, HEIGHT, "miniRT");
	
	minirt->img.img = mlx_new_image(minirt->mlx_ptr, WIDTH, HEIGHT);
	minirt->img.addr = mlx_get_data_addr(minirt->img.img, &minirt->img.bits_per_pixel, &minirt->img.line_length,
		&minirt->img.endian);
	init_camera(minirt);
	// my_mlx_pixel_put(&minirt->img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(minirt->mlx_ptr, minirt->mlx_win, minirt->img.img, 0, 0);
}