/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_conversion2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:25:10 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/22 16:25:15 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**invert_matrix(double **a, int size)
{
	double	**result;
	double	determinante;
	int		i;
	int		j;

	determinante = get_determinant_of_bigger_matrix(a, size);
	if (determinante == 0)
		return (0);
	result = MALLOC(size * (sizeof(double *)));
	i = -1;
	while (++i < size)
		result[i] = MALLOC(size * (sizeof(double)));
	i = -1;
	j = -1;
	while (++i < size)
	{
		while (++j < size)
			result[i][j] = get_cofactor(a, j, i, size) / determinante;
		j = -1;
	}
	return (result);
}

double	get_cofactor(double **a, int i, int j, int size)
{
	if ((i + j) % 2 != 0)
		return (-get_minor(a, i, j, size));
	return (get_minor(a, i, j, size));
}

double	get_determinant_of_bigger_matrix(double **a, int size)
{
	double	result;
	int		i;

	result = 0;
	i = 0;
	while (i < size)
	{
		result = result + get_cofactor(a, 0, i, size) * a[0][i];
		i++;
	}
	return (result);
}

void	free_double_ptr(double **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		FREE(a[i]);
		i++;
	}
	FREE(a);
}
