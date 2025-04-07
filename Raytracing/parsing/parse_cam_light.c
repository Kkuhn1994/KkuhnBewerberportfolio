/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:58:46 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/06 15:22:33 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_ambient_light(t_world *world, char *line)
{
	char	**split;
	int		error;
	double	ratio;
	double	rgb[3];

	check_ambient_light_line(line);
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
	char	**split;
	int		error;
	double	xyz[3];
	double	fov;
	double	normal[3];

	check_camera_line(line);
	split = ft_split(line, ' ');
	if (!split)
		return (1);
	if (budget_ft_atof(split[3]) < 0 || budget_ft_atof(split[3]) > 180)
		exit(1);
	if (parse_xyz_cam_light(split[1], xyz, 0))
		return (ft_free_split(split), 1);
	if (parse_xyz_cam_light(split[2], normal, 1))
		return (ft_free_split(split), 1);
	world->camera->field_of_view = budget_ft_atof(split[3]);
	world->camera->transform = view_transform(set_vector(xyz[0], xyz[1], xyz[2],
				1), set_vector(normal[0], normal[1], normal[2], 0),
			set_vector(0, 1, 0, 0));
	return (ft_free_split(split), 0);
}

void	realloc_light(t_c *canvas, t_light new_light)
{
	t_light	*lights;
	int		i;

	i = 0;
	lights = MALLOC((canvas->num_lights + 1) * sizeof(t_light));
	while (i < canvas->num_lights)
	{
		printf("test");
		lights[i] = canvas->lightsource[i];
		i++;
	}
	lights[i] = new_light;
	printf("newlight");
	FREE(canvas->lightsource);
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

	check_spere_or_light_line(line);
	split = ft_split(line, ' ');
	if (!split)
		return (1);
	if (budget_ft_atof(split[2]) < 0)
		return (ft_free_split(split), 1);
	rgb_split = ft_split(split[3], ',');
	if (!rgb_split)
		return (ft_free_split(split), 1);
	rgb[3] = xyz_rgb_brightness(split, rgb_split, rgb, xyz);
	if (!rgb[3])
		return (1);
	new_light.color = set_vector(rgb[0], rgb[1], rgb[2], rgb[3]);
	new_light.position = set_vector(xyz[0], xyz[1], xyz[2], 0);
	realloc_light(world->canvas, new_light);
	return (ft_free_split(split), ft_free_split(rgb_split), 0);
}
