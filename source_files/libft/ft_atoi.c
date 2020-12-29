/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 10:24:30 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/17 15:33:46 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static char		*skip_spaces(char *str, int *sign)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (*(str + j) != '\0')
	{
		if (*(str + j) == '\v' || *(str + j) == '\f' || *(str + j) == '\r')
			count++;
		else if (*(str + j) == ' ' || *(str + j) == '\t' || *(str + j) == '\n')
			count++;
		else
			break ;
		j++;
	}
	j = 0;
	while (!(*(str + count + j) >= '0' && *(str + count + j) <= '9'))
		j++;
	if (j == 1 && *(str + count) == '-')
		*sign = -1;
	else if (j == 1 && *(str + count) == '+')
		*sign = 1;
	else if (j == 0 && *(str + count) >= '0' && *(str + count) <= '9')
		*sign = 1;
	return (str + count + j);
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

static int		count_digits(char *str)
{
	int i;

	i = 0;
	while (*(str + i) >= '0' && *(str + i) <= '9')
		i++;
	return (i);
}

static int		str_to_int(char *str)
{
	int i;
	int digit;
	int result;
	int digits_amount;

	i = 0;
	result = 0;
	digits_amount = count_digits(str);
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		digit = *(str + i) - '0';
		digit = digit * power(10, digits_amount - 1 - i);
		result = result + digit;
		i++;
	}
	return (result);
}

int				ft_atoi(const char *nptr)
{
	char	*str;
	int		sign;
	int		result;

	if (*nptr == '\0')
		return (0);
	sign = 0;
	str = (char*)nptr;
	str = skip_spaces(str, &sign);
	result = str_to_int(str) * sign;
	return (result);
}
