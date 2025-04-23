/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:41:55 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/22 11:50:23 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double vec3_dot(t_vec3 a, t_vec3 b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double vec3_length(t_vec3 v)
{
	return (sqrt(vec3_dot(v, v)));
}
t_vec3 vec3_normalize(t_vec3 v)
{
	double	len;
	
	len = vec3_length(v);
	if (len == 0)
		return vec3(0, 0, 0);
	return (vec3_scale(v, 1.0 / len));
}

