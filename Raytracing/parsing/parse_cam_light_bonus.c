/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam_light_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:58:46 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 15:40:44 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_ambient_light(t_world *world, char *line)
{
	char	**split;
	int		error;
	double	ratio;
	double	rgb[3];

	check_ambient_light_line(line, world);
	split = ft_split(line, ' ');
	if (!split)
		return (1);
	error = parse_ratio(split[1], &ratio) || parse_rgb(split[2], rgb);
	if (!error)
	{
		*(world->ambient) = set_vector(rgb[0], rgb[1], rgb[2], 0);
		world->ambient_intensity = ratio;
	}
	ft_free_split(split);
	return (error);
}

int	parse_camera(t_world *world, char *line)
{
	char		**split;
	double		xyz[3];
	double		normal[3];
	t_xyzvektor	target;

	check_camera_line(line, world);
	split = ft_split(line, ' ');
	if (!split)
		return (1);
	if (budget_ft_atof(split[3]) < 0 || budget_ft_atof(split[3]) > 180)
		bail("fov between 0 and 180", 1, world);
	if (parse_xyz_cam_light(split[1], xyz, 0))
		return (ft_free_split(split), 1);
	if (parse_xyz_cam_light(split[2], normal, 1))
		return (ft_free_split(split), 1);
	world->camera = camera(world->canvas->width, world->canvas->height,
			budget_ft_atof(split[3]));
	if (!world->camera)
		return (1);
	target = addition(set_vector(xyz[0], xyz[1], xyz[2], 1),
			normalize(set_vector(normal[0], normal[1], normal[2], 0)));
	world->camera->transform = view_transform(set_vector(xyz[0], xyz[1], xyz[2],
				1), target, set_vector(0, 1, 0, 0));
	return (ft_free_split(split), 0);
}

void	realloc_light(t_c *canvas, t_light new_light)
{
	t_light	*lights;
	int		i;

	i = 0;
	lights = ft_malloc((canvas->num_lights + 1) * sizeof(t_light));
	while (i < canvas->num_lights)
	{
		lights[i] = canvas->lightsource[i];
		i++;
	}
	lights[i] = new_light;
	ft_free(canvas->lightsource);
	canvas->lightsource = lights;
	canvas->num_lights++;
}

int	parse_light(t_world *world, char *line)
{
	char	**split;
	double	xyz[3];
	double	rgb[4];
	t_light	new_light;
	char	**rgb_split;

	check_light_line(line, world);
	split = ft_split(line, ' ');
	if (!split)
		bail("split failed", 1, world);
	if (budget_ft_atof(split[2]) < 0)
		bail("value must be above 0", 1, world);
	rgb_split = ft_split(split[3], ',');
	if (!rgb_split)
		bail("couldnt split rgb light", 1, world);
	if (xyz_rgb_brightness(split, rgb_split, rgb, xyz))
		bail("problem parsing light", 1, world);
	new_light.color = set_vector(rgb[0], rgb[1], rgb[2], 0);
	new_light.brightness = budget_ft_atof(split[2]);
	new_light.position = set_vector(xyz[0], xyz[1], xyz[2], 0);
	realloc_light(world->canvas, new_light);
	return (ft_free_split(split), ft_free_split(rgb_split), 0);
}
