/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:50:00 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/26 16:41:31 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
		write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		c = '0' + (n % 10);
		ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(fd, &c, 1);
	}
}

static void	set_base(char *base_chars, int lower)
{
	if (lower == 1)
		ft_strcpy(base_chars, "0123456789abcdef");
	else
		ft_strcpy(base_chars, "0123456789ABCDEF");
}

int	ft_putltohex_fd(unsigned int n, int fd, int lower)
{
	char	result[32];
	char	base_chars[17];
	int		add_char;
	int		len;

	len = 0;
	if (n == 0)
		result[len++] = '0';
	set_base(base_chars, lower);
	while (n != 0)
	{
		add_char = n % 16;
		result[len++] = base_chars[add_char];
		n = n / 16;
	}
	while (len > 0)
		ft_putchar_fd(result[--len], fd);
	return (len);
}

void	ft_putunsigned_fd(unsigned int n, int fd)
{
	char	c;

	if (n > 9)
	{
		c = '0' + (n % 10);
		ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(fd, &c, 1);
	}
}
