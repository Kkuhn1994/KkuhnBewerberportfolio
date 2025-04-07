/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:27:04 by qhahn             #+#    #+#             */
/*   Updated: 2025/03/22 16:27:24 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**shearing(double *proportions)
{
	double	**result;

	result = get_identity_matrix();
	result[0][1] = proportions[0];
	result[0][2] = proportions[1];
	result[1][0] = proportions[2];
	result[1][2] = proportions[3];
	result[2][0] = proportions[4];
	result[2][1] = proportions[5];
	return (result);
}
