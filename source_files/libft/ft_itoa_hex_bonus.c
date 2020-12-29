/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:31 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/25 20:31:17 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		len_nb(int n)
{
	int i;
	int nb;

	i = 0;
	nb = n;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	if (i == 0)
		return (1);
	else
	{
		if (n < 0)
			return (i + 1);
		else
			return (i);
	}
}

static int		power(int base, int pow)
{
	int result;

	result = 1;
	while (pow != 0)
	{
		result = result * base;
		pow--;
	}
	return (result);
}

static char		*operations_for_negative(char *n_str, long *n, int *i)
{
	if (*n < 0)
	{
		*n_str = '-';
		*i = 1;
		*n = *n * -1;
	}
	else
		*i = 0;
	return (n_str);
}

char			*ft_itoa_hex(int n)
{
	int		i;
	long	nb;
	int		len;
	int		result;
	char	*n_str;

	nb = n;
	len = len_nb(nb);
	n_str = (char*)malloc(sizeof(char) * (len + 1));
	if (n_str == NULL)
		return (NULL);
	n_str = operations_for_negative(n_str, &nb, &i);
	while (i < len)
	{
		result = nb / power(16, len - 1 - i);
		result = result % 16;
		if (result < 10)
			*(n_str + i) = result + '0';
		else
			*(n_str + i) = result - 10 + 'a';
		i++;
	}
	*(n_str + i) = '\0';
	return (n_str);
}
