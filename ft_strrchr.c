/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:14 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/20 12:29:18 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*res;
	int		i;
	int		last;
	char	c;

	res = (char *) str;
	i = 0;
	last = 0;
	c = ch;
	while (res[i] != '\0')
	{
		if (res[i] == c)
			last = i;
		i++;
	}
	if (last > 0)
		return (res + last);
	else if (res[i] == c)
		return (res + i);
	else if (res[0] == c)
		return (res);
	return (NULL);
}
