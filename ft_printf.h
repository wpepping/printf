/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:10:13 by wpepping          #+#    #+#             */
/*   Updated: 2024/04/26 17:32:44 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		conversion_i(int i);
int		conversion_c(int c);
int		conversion_s(char *s);
int		conversion_x(int i);
int		conversion_upper_x(int i);
int		conversion_p(void *p);
int		conversion_u(unsigned int i);
int		isin(const char *str, char c);
char	*ft_strcpy(char *dest, char *src);
char	*extstr(char *src, int *buffer);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_pututohex_fd(unsigned int n, int fd, int lower);
int		ft_putultohex_fd(unsigned long n, int fd, int lower);
void	ft_putunsigned_fd(unsigned int n, int fd);
void	output_error(char *error);

#endif
