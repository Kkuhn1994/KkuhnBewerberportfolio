/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:54:09 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/24 17:54:11 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	show_matrix(double **a, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			printf("%f ", a[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

void	show_vector(t_xyzvektor a)
{
	printf("%f %f %f %f", a.x, a.y, a.z, a.w);
}
