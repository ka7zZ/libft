/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:13 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/31 20:25:46 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	int     *values;
    void	*res;
    size_t     i;
	
    i = 0;
    if (n == 0 && size == 1)
    {
        values = malloc((n+1) * size);
        if (values == NULL)
            return (NULL);
        values[n] = '\0';
    }
    if (size == 1)
    {
        values = malloc((n+1) * size);
        if (values == NULL)
            return (NULL);
        while (i <= n)
            values[i++] = '\0';
    }
    else
    {
        values = malloc(n * size);
        if (values == NULL)
                return (NULL);
        while (i < n)
            values[i++] = 0;
    }
    return (res = values);
}
