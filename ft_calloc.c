/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:13 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/09 18:04:06 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*str;
	void	*res;

	if (n == 0 && size >= 1)
	{
		str = malloc((n + 1) * size);
		if (str == NULL)
			return (NULL);
		str[n] = '\0';
	}
	str = malloc((n + 1) * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, n + 1);
	return (res = str);
}
