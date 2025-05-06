/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:17:45 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/20 14:39:20 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../world_building/world.h"

void	assign_to_mat(double **mat, t_xyzvektor left, t_xyzvektor true_up,
		t_xyzvektor forward)
{
	mat[0][0] = left.x;
	mat[0][1] = left.y;
	mat[0][2] = left.z;
	mat[0][3] = 0;
	mat[1][0] = true_up.x;
	mat[1][1] = true_up.y;
	mat[1][2] = true_up.z;
	mat[1][3] = 0;
	mat[2][0] = -forward.x;
	mat[2][1] = -forward.y;
	mat[2][2] = -forward.z;
	mat[2][3] = 0;
}

double	**matrix(t_xyzvektor left, t_xyzvektor true_up, t_xyzvektor forward)
{
	double	**mat;
	int		i;

	mat = (double **)ft_malloc(4 * sizeof(double *));
	if (!mat)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		mat[i] = (double *)ft_malloc(4 * sizeof(double));
		if (!mat[i])
			return (NULL);
		i++;
	}
	assign_to_mat(mat, left, true_up, forward);
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
	return (mat);
}
