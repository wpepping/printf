/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:04:31 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/26 16:17:59 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_conversion(const char *str, va_list args)
{
	if (*str == '%')
		return (conversion_c('%'));
	else if (*str == 'c')
		return (conversion_c(va_arg(args, int)));
	else if (*str == 's')
		return (conversion_s(va_arg(args, char *)));
	else if (*str == 'i' || *str == 'd')
		return (conversion_i(va_arg(args, int)));
	else if (*str == 'x')
		return (conversion_x(va_arg(args, int)));
	else if (*str == 'X')
		return (conversion_upper_x(va_arg(args, int)));
	else if (*str == 'p')
		return (conversion_p(va_arg(args, char *)));
	else if (*str == 'u')
		return (conversion_u(va_arg(args, unsigned int)));
	ft_printf("Invalid conversion character: %c -- SHOULD NOT HAPPEN\n", *str);
	return (-1);
}

int	check_conversion(const char *str)
{
	if (*str == '\0')
		return (1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = 0;
	if (check_conversion(str) == -1)
		return (0);
	while (*str != '\0')
	{
		if (*str == '%')
			len += print_conversion(++str, args);
		else
			len += conversion_c(*(str));
		str++;
	}
	va_end(args);
	return (len);
}
