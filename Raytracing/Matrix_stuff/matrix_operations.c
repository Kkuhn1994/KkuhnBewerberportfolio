/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:25:28 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 20:59:02 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	calculate_element(int row, int column, double **a, double **b)
{
	double	result;
	int		j;
	int		i;

	result = 0;
	j = 0;
	i = 0;
	while (i < 4)
	{
		result += a[row][j] * b[i][column];
		j++;
		i++;
	}
	return (result);
}

double	**multiply_matrix(double **a, double **b)
{
	double	**result;
	int		row;
	int		column;

	row = -1;
	result = ft_malloc(4 * (sizeof(double *)));
	while (++row < 4)
		result[row] = ft_malloc(4 * (sizeof(double)));
	if (!result)
		return (NULL);
	row = -1;
	column = -1;
	while (++row < 4)
	{
		while (++column < 4)
			result[row][column] = calculate_element(row, column, a, b);
		column = -1;
	}
	return (result);
}

t_xyzvektor	multiply_vector_and_matrix(t_xyzvektor a, double **b)
{
	t_xyzvektor	result;

	if (b == 0)
		return (a);
	result.x = a.x * b[0][0] + a.y * b[0][1] + a.z * b[0][2] + a.w * b[0][3];
	result.y = a.x * b[1][0] + a.y * b[1][1] + a.z * b[1][2] + a.w * b[1][3];
	result.z = a.x * b[2][0] + a.y * b[2][1] + a.z * b[2][2] + a.w * b[2][3];
	result.w = a.w;
	return (result);
}

double	**get_identity_matrix(void)
{
	double	**a;
	int		i;

	i = -1;
	a = ft_calloc(4, (sizeof(double *)));
	while (++i < 4)
		a[i] = ft_calloc(4, (sizeof(double)));
	a[0][0] = 1;
	a[1][1] = 1;
	a[2][2] = 1;
	a[3][3] = 1;
	return (a);
}

int	compare_matrix(double **a, double **b, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (fabs(a[i][j] - b[i][j]) > 0.001)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
