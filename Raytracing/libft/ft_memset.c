/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:01:33 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/07 14:38:58 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char) c;
		i ++;
	}
	return (b);
}

// int main()
// {
//     char str1[20];
//     char str2[20];
//     int c = 'A';
//     size_t len = 10;
//     // Mit ft_memset initialisieren
//     ft_memset(str1, c, len);
//     printf("Mit ft_memset initialisiert: %s\n", str1);
//     // Mit echter memset initialisieren
//     memset(str2, c, len);
//     printf("Mit memset initialisiert: %s\n", str2);
//     // Vergleichen der Ergebnisse
//     if (memcmp(str1, str2, len) == 0)
//         printf("Die Initialisierung war erfolgreich.\n");
//     else
//         printf("Die Initialisierung war nicht erfolgreich.\n");
// }