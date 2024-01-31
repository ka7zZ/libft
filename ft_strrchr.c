/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:14 by aghergut          #+#    #+#             */
/*   Updated: 2024/01/10 19:21:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	last;

	i = 0;
	last = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			last = i;
		i++;
	}
	if (last > 0)
		return (str + last);
	return (0);
}
