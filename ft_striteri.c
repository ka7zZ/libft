/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:29:04 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/26 14:34:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
    size_t          max;

	if (s && f)
	{
		i = 0;
        max = ft_strlen(s);
		while (i < max)
		{
			(*f)(i, s);
            i++;
		}
	}
}
