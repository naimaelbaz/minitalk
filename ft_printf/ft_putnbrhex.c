/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:50:04 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/08 22:46:42 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_size(unsigned long long n, int b)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= b;
		count++;
	}
	return (count);
}

static char	*ft_itoabase(unsigned long long n, char *base, int b)
{
	int		ln;
	char	*ptr;

	ln = count_size(n, b);
	ptr = (char *)malloc(sizeof(char) * (ln + 1));
	if (!ptr)
		return (NULL);
	ptr[ln--] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[ln] = base[n % b];
		n /= b;
		ln--;
	}
	return (ptr);
}

int	ft_putnbrhex(unsigned long long n, char *base, int b)
{
	char	*str;
	int		len;

	str = ft_itoabase(n, base, b);
	len = ft_putstr(str);
	free(str);
	str = NULL;
	return (len);
}

int	ft_putpointer(unsigned long long n)
{
	int	i;

	i = ft_putstr("0x");
	i += ft_putnbrhex(n, "0123456789abcdef", 16);
	return (i);
}
