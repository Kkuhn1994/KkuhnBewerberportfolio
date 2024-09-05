/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:20:12 by kkuhn             #+#    #+#             */
/*   Updated: 2024/07/27 18:30:16 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	char	*allocated_memory;

	allocated_memory = (void *) malloc (count * size);
	if (allocated_memory == 0)
		return (NULL);
	ft_memset(allocated_memory, 0, count * size);
	return (allocated_memory);
}

// int main() {
//     int *intArray;
//     char *str;
// 	 char *str2;
//     // Testfall 1: Allokieren und Initialisieren eines Integer-Arrays
//     intArray = (int *)ft_calloc(5, sizeof(int));
//     printf("Integer-Array nach calloc:\n");
//     for (int i = 0; i < 5; ++i) {
//         printf("%d ", intArray[i]);  // 
//     }
//     printf("\n");
//     free(intArray);  // Speicher freigeben
//     // Testfall 2: Allokieren und Initialisieren einer Zeichenkette
//     str = (char *)ft_calloc(10, sizeof(char)); 
//     printf("Zeichenkette nach calloc: %s\n", str);  // Sollte "Hello" sein
//     free(str);  // Speicher freigeben

// 	    intArray = (int *)ft_calloc(5, sizeof(int));
//     printf("Integer-Array nach calloc:\n");
//     for (int i = 0; i < 5; ++i) {
// printf("%d ", intArray[i]);  // 
//     }
//     printf("\n");
//     free(intArray);  // Speicher freigeben
//     // Testfall 2: Allokieren und Initialisieren einer Zeichenkette
//     str2 = (char *)calloc(10, sizeof(char));
//     printf("Zeichenkette nach calloc: %s\n", str);  // Sollte "Hello" sein
//     free(str);  // Speicher freigeben
//     return 0;
// }