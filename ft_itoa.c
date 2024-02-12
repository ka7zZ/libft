/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:34:20 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/12 17:38:02 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	v_length(int value)
{
	int	len;
	int	temp;

	len = 1;
	if (value < 10)
		return (len);
	temp = value;
	while (temp > 9)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

static void	*free_mem(void *str)
{
	free(str);
	return (NULL);
}

char	*negative(int len, int value)
{
	char	*number;

	number = malloc((len + 2) * sizeof(char));
	if (number == NULL)
		return (free_mem(number));
	number[len + 1] = '\0';
	while (len-- > 0)
	{
		number[len] = (value % 10) + '0';
		value /= 10;
	}
	number[len] = '-';
	return (number);
}

static char	*positive(int len, int value)
{
	char	*number;

	number = malloc((len + 1) * sizeof(char));
	if (number == NULL)
		return (free_mem(number));
	number[len] = '\0';
	while (--len >= 0)
	{
		number[len] = (value % 10) + '0';
		value /= 10;
	}
	return (number);
}

char	*ft_itoa(int value)
{
	int		len;
	int		kind;

	kind = 1;
	if (value < 0)
		kind = 0;
	len = v_length(value);
	if (kind == 0)
		return (negative(len, value));
	return (positive(len, value));
}
