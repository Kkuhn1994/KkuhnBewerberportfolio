/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:20:43 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/06 20:20:43 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// void	ft_toupper2(unsigned int i,char *c)
// {
// 	if(*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		(f)(i, &s[i]);
		i ++;
	}
}

// int main(void)
// {
// 	char string[] = "awcgc133";
// 	printf("%s\n", string);
// 	ft_striteri(string, &ft_toupper2);
// 	printf("%s\n", string);
// 	return 0;
// }