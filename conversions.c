/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:16:06 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/26 16:19:20 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	nr_of_chars(int n)
{
	int	i;
	int	pow;

	i = 1;
	pow = 1;
	if (n == -2147483648)
		n = n + 1;
	if (n < 0)
	{
		n = 0 - n;
		i += 1;
	}
	while (n / pow >= 10)
	{
		i++;
		pow *= 10;
	}
	return (i);
}

int	conversion_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	conversion_i(int i)
{
	ft_putnbr_fd(i, 1);
	return (nr_of_chars(i));
}

int	conversion_u(unsigned int i)
{
	ft_putunsigned_fd(i, 1);
	return (nr_of_chars(i));
}
