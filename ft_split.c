/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:58:07 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/02 01:54:06 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "libft.h"

// Function for count the total splits:
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

// Function FREE
void	*free_mem(void *p)
{
	free(p);
	return (NULL);
}

// Function split:

char	**ft_split(char *str, char c)
{
	char	**splits;
	int		arr_pointer;
	int		arr_idx;
	int		str_idx;
	int		start_idx;

	splits = (char **) malloc((count_arrays(str, c) + 1) * sizeof(char *));
	if (!splits)
		return (free_mem(splits));
	arr_pointer = 0;
	arr_idx = 0;
	str_idx = 0;
	start_idx = 0;
	while (str[str_idx] != '\0')
	{
		if (str[str_idx] == c && str_idx == 0)
		{
			length = ((str_idx - start_idx) + 1)
splits[arr_pointer] = (char *) malloc(length * sizeof(char));	
			if (!splits[arr_pointer])
				return (free_mem(splits[arr_pointer]));
			splits[arr_pointer][arr_idx] = '\0';
			start_idx += 1;
			arr_pointer++;
		}
		if (str[str_idx] == c && str_idx > 0)
		{
splits[arr_pointer] = (char *) malloc(length * sizeof(char));
			if (!splits[arr_pointer])
				return (free_mem(splits[arr_pointer]));
			while (start_idx < str_idx)
				splits[arr_pointer][arr_idx++] = str[start_idx++];
			splits[arr_pointer][arr_idx] = '\0';
			start_idx++;
			arr_pointer++;
		}
		arr_idx = 0;
		str_idx++;
	}
splits[arr_pointer] = (char *) malloc(length * sizeof(char));
	if (!splits[arr_pointer])
		return (free_mem(splits[arr_pointer]));
	while (start_idx < str_idx)
		splits[arr_pointer][arr_idx++] = str[start_idx++];
	splits[arr_pointer][arr_idx] = '\0';
	splits[arr_pointer + 1] = '\0';
	return (splits);
}
*/