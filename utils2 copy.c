/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirueta- <mirueta-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:53:53 by mirueta-          #+#    #+#             */
/*   Updated: 2021/11/10 16:58:58 by mirueta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	printhexa(size_t num, char c)
{
	int		len;

	len = 0;
	if (c == 'x' || c == 'p')
	{
		if (num < 16)
			len += printchar((int)BASEMIN[num % 16]);
		else
		{
			len += printhexa((num / 16), c);
			len += printchar((int)BASEMIN[num % 16]);
		}
	}
	else
	{
		if (num < 16)
			len += printchar((int)BASEMAX[num % 16]);
		else
		{
			len += printhexa((num / 16), c);
			len += printchar((int)BASEMAX[num % 16]);
		}
	}
	return (len);
}

int	printunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		len += printchar(n + '0');
	else
	{
		len += printnbr(n / 10);
		len += printchar((n % 10) + '0');
	}
	return (len);
}
