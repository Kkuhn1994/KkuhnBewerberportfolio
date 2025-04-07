/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_light_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:55:25 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/04 13:56:31 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

double	xyz_rgb_brightness(char **split, char **rgb_split, double rgb[4],
		double xyz[3])
{
	double	brightness;

	parse_xyz_cam_light(split[1], xyz, 0);
	if (!parse_xyz(rgb_split, rgb, 0))
		return (ft_free_split(split), ft_free_split(rgb_split), 1);
	rgb[0] /= 255;
	rgb[1] /= 255;
	rgb[2] /= 255;
	if (rgb[0] < 0 || rgb[0] > 1 || rgb[1] < 0 || rgb[1] > 1 || rgb[2] < 0
		|| rgb[2] > 1)
		return (ft_free_split(split), ft_free_split(rgb_split), 1);
	brightness = budget_ft_atof(split[2]);
	if (brightness < 0 || brightness > 1)
		return (ft_free_split(split), ft_free_split(rgb_split), 1);
	return (brightness);
}

int	parse_xyz_cam_light(char *str, double xyz[3], int is_normal)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(str, ',');
	if (!split || count_split(split) != 3)
	{
		ft_free_split(split);
		return (1);
	}
	while (++i < 3)
	{
		xyz[i] = budget_ft_atof(split[i]);
		if (is_normal && (xyz[i] < -1.0 || xyz[i] > 1.0))
		{
			ft_free_split(split);
			return (1);
		}
	}
	ft_free_split(split);
	return (0);
}

int	parse_fov(char *str, double *fov)
{
	*fov = budget_ft_atof(str);
	if (*fov < 0.0 || *fov > 180.0)
		return (1);
	return (0);
}
