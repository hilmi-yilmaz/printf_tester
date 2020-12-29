/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:31 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/14 18:46:48 by hyilmaz       ########   odam.nl         */
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
		nb = nb / 10;
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

static char		*operations_for_negative(char *n_str, int *n, int *i)
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

static char		*lowest_int(char *str)
{
	char	*n_str;
	int		i;

	i = 0;
	n_str = (char*)malloc(sizeof(char) * 12);
	if (n_str == NULL)
		return (NULL);
	while (i < 11)
	{
		*(n_str + i) = *(str + i);
		i++;
	}
	*(n_str + i) = '\0';
	return (n_str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		len;
	int		result;
	char	*n_str;

	if (n == -2147483648)
		return (lowest_int("-2147483648"));
	len = len_nb(n);
	n_str = (char*)malloc(sizeof(char) * (len + 1));
	if (n_str == NULL)
		return (NULL);
	n_str = operations_for_negative(n_str, &n, &i);
	while (i < len)
	{
		result = n / power(10, len - 1 - i);
		result = result % 10;
		*(n_str + i) = result + '0';
		i++;
	}
	*(n_str + i) = '\0';
	return (n_str);
}
