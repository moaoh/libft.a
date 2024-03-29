/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 01:12:11 by junmkang          #+#    #+#             */
/*   Updated: 2020/10/16 20:24:10 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char		*chk(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (ft_strdup("0"));
}

static void		ft_print(char *str, int n, int len)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648 || n == 0)
		return (chk(n));
	len = count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	ft_print(str, n, len - 1);
	return (str);
}
