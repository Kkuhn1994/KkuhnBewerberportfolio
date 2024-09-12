/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuhn <kkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:16:12 by kkuhn             #+#    #+#             */
/*   Updated: 2024/03/14 20:18:06 by kkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d",ft_isdigit('a'));
// 	printf("%d",ft_isdigit('G'));
// 	printf("%d",ft_isdigit('k'));
// 	printf("%d",ft_isdigit('='));
// 	printf("%d",ft_isdigit('0'));
// 	printf("%d",ft_isdigit(' '));
// 	return (0);
// }