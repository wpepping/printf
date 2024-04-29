/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:16:17 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/26 18:34:41 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isin(const char *str, char c)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*(str++) == c)
			return (1);
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++] != '\0')
		;
	return (i - 1);
}
