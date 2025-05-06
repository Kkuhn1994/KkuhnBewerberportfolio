/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbageCollector.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhahn <qhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:28:27 by qhahn             #+#    #+#             */
/*   Updated: 2025/04/19 20:59:02 by qhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGECOLLECTOR_H
# define GARBAGECOLLECTOR_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

void	*get_adress_of_list(void);
void	*ft_malloc(int size);
void	free_list(void) __attribute__((destructor));
void	*rt_realloc(void *ptr, int new_size);
#endif