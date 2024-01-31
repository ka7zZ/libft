/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:04 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/31 17:04:13 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void printString(int idx, char *s)
{
	printf("The char: %c have the index: %d\n", *s, idx);
}

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		(*f)(i++, s);
		s++;
	}
}

int	main(void)
{
	char	*s = "abracadabra";
	ft_striteri(s, printString);
	return(0);
}
