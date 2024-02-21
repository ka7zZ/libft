/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:58:07 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/21 17:17:32 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	count_arrays(char *str, char c)
{
	int	word;
	int	last_idx;

	word = 0;
	last_idx = (int)ft_strlen(str) - 1;
	while (*str)
	{
		if (*str == (char) NULL)
			return (word);
		while (*str == c)
			str++;
		if (*str != (char) NULL)
			word++;
		while (*str != c && *str != (char) NULL)
			str++;
	}
	return (word);
}

static void	free_memory(char **s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == NULL)
			free(s[i]);
		i++;
	}
}

static char	**assign(char **sp, int sp_i, char *s, char c, int f, int s_i)
{
	char	*cstr;

	cstr = s;
	while (*s)
	{
		while (*s == c)
		{
			s_i++;
			f++;
			s++;
		}
		while (*s != c && s_i < (int) ft_strlen(cstr) - 1 && *s != (char) NULL)
		{
			s_i++;
			s++;
		}
		if (*s == c)
		{
			sp[sp_i] = ft_substr(cstr, f, s_i - f);
			f = s_i + 1;
			sp_i++;
		}
		s_i++;
		s++;
	}
	if (s_i == (int) ft_strlen(cstr))
		sp[sp_i] = ft_substr(cstr, f, s_i - f);
	return (sp);
}

char	**ft_split(char *str, char c)
{
	char	**splits;
	int		i;

	i = 0;
	splits = (char **) ft_calloc((count_arrays(str, c) + 1), sizeof(char *));
	if (!splits)
		return (0);
	if (str[i] == '\0')
		return (splits);
	splits = assign(splits, 0, str, c, 0, 0);
	free_memory(splits);
	return (splits);
}
