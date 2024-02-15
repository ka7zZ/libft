/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:09:17 by aghergut          #+#    #+#             */
/*   Updated: 2024/02/15 13:42:05 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n);

static int	obtain_digit(int n, int temp, int len, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < len)
		temp *= 10;
	n = n - temp;
	if (n < 0)
		return (n);
	j = n_len(n);
	if (j - 1 != len - 2)
	{
		len = len - n_len(n);
		while (len - 1 > 0)
		{
			write(fd, "0", 1);
			len--;
		}
	}
	return (n);
}

static int	n_len(int n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	write_number(int n, int fd, int len)
{
	int		temp;
	char	ch;
	int		len_new;

	while (len >= 0)
	{
		temp = n;
		if (temp >= 0)
		{
			while (temp > 9)
				temp /= 10;
			ch = temp + '0';
			write(fd, &ch, 1);
			n = obtain_digit(n, temp, len, fd);
			len_new = n_len(n);
			if (len_new != len - 1)
				len = len_new + 1;
			if (n < 10 && n > 0)
			{
				ch = n + '0';
				write(fd, &ch, 1);
				len = 0;
			}
		}
		len--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	ch;

	if (n >= -2147483648 && n <= 2147483647)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		if (n < 0 && n != -2147483648)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		if (n >= 0)
		{
			if (n < 10)
			{
				ch = n + '0';
				write(fd, &ch, 1);
			}
			else
			{
				len = n_len(n);
				write_number(n, fd, len);
			}
		}
	}
}