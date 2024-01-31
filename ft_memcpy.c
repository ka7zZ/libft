/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:29 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/15 17:27:31 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*castD;
	unsigned char	*castS;
	size_t		i;

	if (src == NULL)
		return (NULL);
	castD = (unsigned char *)dst;
	castS = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		castD[i] = castS[i];
		i++;
	}
	return (dst = castD);
}

int	main(void)
{
	char	src[10] = "source";
	char	dest[20] = "destination";

	//memcpy(dest, src, strlen(src) * sizeof(char));
	ft_memcpy(dest, src, strlen(src) * sizeof(char));
	printf("%s\n", dest);
	return (0);
}
