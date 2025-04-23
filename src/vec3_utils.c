/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedenec <amedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:32:06 by amedenec          #+#    #+#             */
/*   Updated: 2025/04/22 16:20:24 by amedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3 vec3(double x, double y, double z)
{
    t_vec3 v;
    
    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
}

t_vec3 vec3_add(t_vec3 a, t_vec3 b)
{
    return (vec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec3 vec3_sub(t_vec3 a, t_vec3 b)
{
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

t_vec3 vec3_scale(t_vec3 v, double s)
{
    return vec3(v.x * s, v.y * s, v.z * s);
}

t_vec3 vec3_cross(t_vec3 a, t_vec3 b)
{
    return vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}



