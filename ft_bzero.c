/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:16 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/02 01:56:52 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cast;
	size_t			i;

	cast = (unsigned char *) s;
	if (cast != NULL)
	{
		i = 0;
		while (i < n)
		{
			cast[i] = 0;
			i++;
		}
		s = cast;
	}
}
