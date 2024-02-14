/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:58:07 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/13 17:50:32 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_arrays(char *str, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			word++;
		i++;
	}
	return (word);
}

char	**ft_split(char *str, char c)
{
	char	**splits;
	int		arr_pointer;
	int		arr_idx;
	int		str_idx;
	int		start_idx;
	int		length;

	splits = (char **) malloc((count_arrays(str, c) + 1) * sizeof(char *));
	if (!splits)
		return (NULL);
	arr_pointer = 0;
	arr_idx = 0;
	str_idx = 0;
	start_idx = 0;
	while (*str != '\0')
	{
		if (*str == c && str_idx == 0)
		{
			str++;
			str_idx++;
			start_idx++;
		}
		if (*str == c)
		{
			length = str_idx - start_idx;
			splits[arr_pointer] = ft_substr(str, start_idx, length);
			start_idx = str_idx + 1;
			arr_pointer++;
		}
		arr_idx = 0;
		str_idx++;
		str++;
	}
	splits[arr_pointer] = '\0';
	return (splits);
}
