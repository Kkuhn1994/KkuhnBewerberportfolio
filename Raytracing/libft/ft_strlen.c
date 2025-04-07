/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:04:03 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/06 20:06:50 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (*str != 0)
	{
		i ++;
		str ++;
	}
	return (i);
}

// int main (void){
//    printf("%lu", ft_strlen("cjkabkdbab"));
//    printf("%lu", strlen("cjkabkdbab"));
// }