/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:23 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/22 14:07:40 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;
	size_t	i;

	i = 0;
	res = (unsigned char *)s;
	while (i < n)
	{
		if (res[i] == c)
			return (res + i);
		i++;
	}
	return (0);;
}
