/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:16 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/31 19:11:35 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bzero(void *s, size_t n)
{
	unsigned char	*cast;
	size_t		i;

	if (s != NULL)
    {
	    cast = (unsigned char *)s;
	    i = 0;
    	while (i < n)
	    {
		    cast[i] = 0;
    		i++;
	    }
    	s = cast;
    }
}