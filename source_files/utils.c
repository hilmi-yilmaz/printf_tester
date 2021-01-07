/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 20:33:06 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/26 12:03:20 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_nblen(long nb, int base)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

int		max_number(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

/*
** The ft_strchr function searches for the character c in the string s.
** If found, it returns 1, else returns 0.
*/

int		ft_strchr1(char *s, int c)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int		ft_cntchr(char *str, int c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == c)
			count++;
		i++;
	}
	return (count);
}
