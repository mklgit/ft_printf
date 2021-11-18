/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirueta- <mirueta-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:27:24 by mirueta-          #+#    #+#             */
/*   Updated: 2021/11/10 17:00:58 by mirueta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

int	set_value(char *format, int i, va_list arg)
{
	int		len;

	len = 0;
	if (format[i + 1] == 'c')
		len = printchar(va_arg(arg, int));
	if (format[i + 1] == 's')
		len = printstr(va_arg(arg, char *));
	if (format[i + 1] == 'd')
		len = printnbr(va_arg(arg, int));
	if (format[i + 1] == 'i')
		len = printnbr(va_arg(arg, int));
	if (format[i + 1] == 'u')
		len = printunbr(va_arg(arg, unsigned int));
	if (format[i + 1] == 'p')
		len = printstr("0x") + printhexa(va_arg(arg, size_t), 'p');
	if (format[i + 1] == 'x')
		len = printhexa(va_arg(arg, unsigned int), 'x');
	if (format[i + 1] == 'X')
		len = printhexa(va_arg(arg, unsigned int), 'X');
	if (format[i + 1] == '%')
		len = printchar('%');
	return (len);
}

int	put_format(const char *format, va_list arg)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	str = ft_strdup(format);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		else
		{
			len += set_value(str, i, arg);
			i++;
		}
		i++;
	}
	free(str);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	if (!format)
		return (0);
	len = 0;
	va_start(arg, format);
	len = put_format(format, arg);
	va_end(arg);
	return (len);
}
