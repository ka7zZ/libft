/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:15:18 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/09 15:05:00 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *) str;
	while (res[i] != '\0')
	{
		if (res[i] == ch)
			return (res + i);
		i++;
	}
	if (res[i] == ch)
		return (res + i);
	return (0);
}
