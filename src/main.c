/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adam <adam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:45:55 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/23 06:56:36 by adam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(void)
{
	t_miniRT	minirt;
	
	init(&minirt);
	draw(&minirt);
	//mlx_hook(minirt.mlx_win, 6, 1L << 6, mouse_move_handler, &minirt);
	mlx_loop(minirt.mlx_ptr);
	return (0);
}
