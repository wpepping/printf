/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:56:15 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/26 16:17:53 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conversion_p(void *p)
{
	ft_putstr_fd("0x", 1);
	return (ft_putltohex_fd((unsigned long)p, 1, 1) + 2);
}

int	conversion_s(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	conversion_upper_x(int i)
{
	return (ft_putltohex_fd(i, 1, 0));
}

int	conversion_x(int i)
{
	return (ft_putltohex_fd(i, 1, 1));
}
