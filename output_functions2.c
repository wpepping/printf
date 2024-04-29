/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:13:05 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/28 14:01:13 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_base(char *base_chars, int lower)
{
	if (lower == 1)
		ft_strcpy(base_chars, "0123456789abcdef");
	else
		ft_strcpy(base_chars, "0123456789ABCDEF");
}

int	ft_putultohex_fd(unsigned long n, int fd, int lower)
{
	char	result[32];
	char	base_chars[17];
	int		add_char;
	int		len;
	int		result_len;

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
	result_len = len;
	while (len > 0)
		ft_putchar_fd(result[--len], fd);
	return (result_len);
}

int	ft_pututohex_fd(unsigned int n, int fd, int lower)
{
	char	result[32];
	char	base_chars[17];
	int		add_char;
	int		len;
	int		result_len;

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
	result_len = len;
	while (len > 0)
		ft_putchar_fd(result[--len], fd);
	return (result_len);
}

void	ft_putunsigned_fd(unsigned int n, int fd)
{
	char	c;

	if (n > 9)
	{
		c = '0' + (n % 10);
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(c, fd);
	}
	else
	{
		c = '0' + n;
		ft_putchar_fd(c, fd);
	}
}
