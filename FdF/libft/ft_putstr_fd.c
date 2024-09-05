/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:50:11 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/06 20:50:12 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	{
		while (*s != 0)
		{
			write(fd, s, 1);
			s ++;
		}
	}
}

// int	main(void)
// {
// 	ft_putstr_fd("hallo wie geht es dir heute", 1);
// 	return (0);
// }
