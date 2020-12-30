/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   d_convert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 20:20:31 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/30 09:59:28 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
** The d_convert function prints the {d, i, u}-conversion.
** It uses ft_strlen, ft_itoa and ft_putstr_fd from libft.
** It also uses the below three functions.
**
** Arguments:
**		(va_list)	ap: the argument list which contains the unnamed arguments.
**		(t_info *)	info: pointer to struct which contains the conversion
**					information.
**
** Returns:
** 		(void) 		None.
*/

void	d_convert(va_list ap, t_info *info)
{
	int		nb;
	int		len_nb;
	char	*str_nb;
	char	*str;

	if (info->spec == 'd' || info->spec == 'i')
		nb = va_arg(ap, int);
	if (info->spec == 'u')
		nb = va_arg(ap, unsigned int);
	str_nb = ft_itoa(nb);
	if (str_nb == NULL)
	{
		info->err = 1;
		return ;
	}
	len_nb = ft_strlen(str_nb);
	str = create_array(nb, info, len_nb);
	info->return_val = ft_strlen(str);
	fill_zeros(str, info, nb, 10);
	fill_nb(str, str_nb, info, nb);
	ft_putstr_fd(str, 1);
	free(str);
	free(str_nb);
}

/*
** The create_array function allocates exactly enough memory for the string.
** It also fills it with spaces using the ft_memset function from libft.
**
** Arguments:
**		(int)		nb: the number to print.
**		(t_info *)	info: pointer to struct which contains the conversion
**					information.
**		(int)		len_nb: the length of the number including '-' sign.
**
** Returns:
**		(char *) 	str: string which is filled with spaces.
*/

char	*create_array(int nb, t_info *info, int len_nb)
{
	int		len_str;
	char	*str;

	if (len_nb >= info->prec)
		len_str = len_nb;
	else
		len_str = info->prec;
	if (len_str < info->width)
		len_str = info->width;
	if (nb == 0 && info->prec == -1)
		len_str = 1;
	if (nb == 0 && info->prec == 0)
		len_str = info->width;
	if (nb < 0 && info->prec >= len_nb && info->prec >= info->width)
		len_str++;
	str = (char *)malloc(sizeof(char) * len_str + 1);
	if (str == NULL)
	{
		info->err = 1;
		return (NULL);
	}
	if (info->zero == 0)
		ft_memset(str, ' ', (size_t)len_str);
	else
		ft_memset(str, '0', (size_t)len_str);
	*(str + len_str) = '\0';
	return (str);
}

/*
** The fill_zeros function fills the string "str" with zeros.
** It fills a maximum of info->prec zeros or length of the number
** (including - sign).
** It takes into account the left or right adjustment parameter info->dash.
**
** Arguments:
**		(char *) 	str: the string to be filled with zeros.
**		(t_info *)	info: pointer to struct which contains the conversion
**					information.
**		(int)		base: the base number to do the calculations (base^power).
**
** Returns:
**		(void) 		None.
*/

void	fill_zeros(char *str, t_info *info, int nb, int base)
{
	int i;
	int j;
	int	prec;

	if (info->prec == -1)
		prec = 0;
	else
		prec = info->prec;
	if (info->dash == 0)
		i = ft_strlen(str) - prec;
	else
	{
		if (nb < 0)
			i = 1;
		else
			i = 0;
	}
	j = 0;
	while (*(str + i) != '\0' && (j < prec || j < ft_nblen(nb, base)))
	{
		*(str + i) = '0';
		i++;
		j++;
	}
}

/*
** The fill_nb function fills the string with the number.
**
** Arguments:
**		(char *)	str: the string to be filled.
**		(char *)	str_nb: the number in a string (result of ft_itoa).
**		(t_info *)	info: pointer to struct which contains the conversion
**					information.
**		(int)		nb: the number to print.
**
** Returns:
**		(void) 		None.
*/

void	fill_nb(char *str, char *str_nb, t_info *info, int nb)
{
	int i;
	int j;

	if (nb < 0 && info->dash == 1)
		*(str + 0) = '-';
	i = ft_strlen(str) - 1;
	j = ft_strlen(str_nb) - 1;
	if (i < 0)
		i = 0;
	while (*(str + i) == ' ' && info->dash == 1)
		i--;
	while (j >= 0 && *(str_nb + j) != '-')
	{
		if (*str == '\0' || (info->prec == 0 && nb == 0))
			break ;
		*(str + i) = *(str_nb + j);
		i--;
		j--;
	}
	i = 0;
	while (ft_isdigit(*(str + i)) == 0 && nb < 0 && info->dash == 0)
		i++;
	if (nb < 0 && info->dash == 0)
		*(str + i - 1) = '-';
}
