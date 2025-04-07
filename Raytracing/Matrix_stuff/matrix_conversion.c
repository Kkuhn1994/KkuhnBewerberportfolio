/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:20:45 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/22 16:21:06 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**transpose_matrix(double **a, int size)
{
	double	**result;
	int		i;
	int		j;

	result = MALLOC(size * (sizeof(double *)));
	i = -1;
	while (++i < size)
		result[i] = MALLOC(size * (sizeof(double)));
	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			result[i][j] = a[j][i];
			j++;
		}
		j = 0;
		i++;
	}
	return (result);
}

double	get_determinante_of_3x3(double **a)
{
	double	**submatrix1;
	double	**submatrix2;
	double	**submatrix3;
	double	determinante;

	submatrix1 = get_submatrix(a, 0, 0, 3);
	submatrix2 = get_submatrix(a, 0, 1, 3);
	submatrix3 = get_submatrix(a, 0, 2, 3);
	determinante = (a[0][0] * get_determinante_of_2(submatrix1) - a[0][1]
			* get_determinante_of_2(submatrix2) + a[0][2]
			* get_determinante_of_2(submatrix3));
	free_double_ptr(submatrix1, 2);
	free_double_ptr(submatrix2, 2);
	free_double_ptr(submatrix3, 2);
	return (determinante);
}

double	get_minor(double **a, int i, int j, int size)
{
	double	**submatrix;
	double	determinante;

	submatrix = get_submatrix(a, i, j, size);
	if (size == 3)
		determinante = get_determinante_of_2(submatrix);
	else
		determinante = get_determinante_of_3x3(submatrix);
	free_double_ptr(submatrix, size - 1);
	return (determinante);
}

double	get_determinante_of_2(double **a)
{
	return (a[0][0] * a[1][1] - a[1][0] * a[0][1]);
}

// double calculate_element(int row, int column, double **a, double **b)
// {
// 	double result;
// 	int j;
// 	int i;

// 	result = 0;
// 	j = 0;
// 	i = 0;
// 	while(i < 4)
// 	{
// 		result += a[row][j] * b[i][column];
// 		j ++;
// 		i ++;
// 	}
// 	return (result);
// }

// double **multiply_matrix(double **a, double **b)
// {
// 	double **result;
// 	int row;
// 	int column;

// 	row = -1;
// 	result = malloc(4 * (sizeof(double *)));
// 	while (++ row < 4)
// 		result[row] = malloc(4 * (sizeof(double)));
// 	row = -1;
// 	column = -1;
// 	while (++ row < 4)
// 	{
// 		while(++ column < 4)
// 			result[row][column] = calculate_element(row, column, a, b);
// 		column = -1;
// 	}
// 	return (result);
// }