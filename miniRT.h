/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:48:44 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/22 12:09:18 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# define WIDTH 1000
# define HEIGHT 1000

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_miniRT
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;
}	t_miniRT;

// vec3
typedef struct s_vec3
{
	double x;
	double y;
	double z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct	s_sphere
{
	t_vec3	origin;
	double	radus;
}	t_sphere;



// init
void	init(t_miniRT *minirt);

// vec3_utils1
t_vec3 vec3(double x, double y, double z);
t_vec3 vec3_add(t_vec3 a, t_vec3 b);
t_vec3 vec3_add(t_vec3 a, t_vec3 b);
t_vec3 vec3_scale(t_vec3 v, double s);
t_vec3 vec3_cross(t_vec3 a, t_vec3 b);

// vec3_utils2
double vec3_dot(t_vec3 a, t_vec3 b);
double vec3_length(t_vec3 v);
t_vec3 vec3_normalize(t_vec3 v);

// draw
void    draw(t_miniRT *minirt);

#endif
