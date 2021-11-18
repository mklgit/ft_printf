/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirueta- <mirueta-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:39:57 by mirueta-          #+#    #+#             */
/*   Updated: 2021/11/10 16:55:09 by mirueta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

int	printchar(int c)
{
	int	len;

	len = 0;
	ft_putchar_fd(c, 1);
	len++;
	return (len);
}

int	printstr(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	if (!str)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	while (str[++i])
		len += write(1, &str[i], 1);
	return (len);
}

int	printnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (printstr("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		len += printchar('-');
		len += printnbr(n);
	}
	else if (n < 10)
		len += printchar(n + '0');
	else
	{
		len += printnbr(n / 10);
		len += printchar((n % 10) + '0');
	}
	return (len);
}
