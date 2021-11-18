/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirueta- <mirueta-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:00:15 by mirueta-          #+#    #+#             */
/*   Updated: 2021/11/10 17:03:22 by mirueta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>

# define BASEMIN "0123456789abcdef"
# define BASEMAX "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	put_format(const char *format, va_list arg);
int	set_value(char *format, int i, va_list arg);
int	printchar(int c);
int	printstr(char *str);
int	printnbr(int num);
int	printunbr(unsigned int num);
int	printhexa(size_t num, char c);

#endif
