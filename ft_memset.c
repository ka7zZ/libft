/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:34 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/10 17:50:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*cStr;
	size_t	i;

	if (str == NULL)
		return (NULL);
	cStr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		cStr[i] = (unsigned char)c;
		i++;
	}
	return (str = cStr);
}
