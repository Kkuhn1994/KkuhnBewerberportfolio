/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:25:43 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/22 16:26:06 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	*extract_submatrix_row(double *a, int ii, int size)
{
	double	*row;
	int		i;
	int		j;

	i = 0;
	j = 0;
	row = MALLOC((size - 1) * (sizeof(double)));
	while (i < size)
	{
		if (i != ii)
		{
			row[j] = a[i];
			j++;
		}
		i++;
	}
	return (row);
}

double	**get_submatrix(double **a, int ii, int jj, int size)
{
	double	**result;
	int		i;
	int		j;

	result = MALLOC((size - 1) * (sizeof(double *)));
	j = 0;
	i = 0;
	while (i < (size))
	{
		if (i != ii)
		{
			result[j] = extract_submatrix_row(a[i], jj, size);
			j++;
		}
		i++;
	}
	return (result);
}
