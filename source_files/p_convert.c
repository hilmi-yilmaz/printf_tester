/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_convert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 18:41:39 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/27 13:50:04 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
** The p_convert function prints the p-conversion.
** It uses the ft_strlen, ft_ultoa_hex and ft_putstr_fd.
** It also uses the below two functions.
**
** Arguments:
**		(va_list)	ap: the argument list which contains the unnamed arguments.
**		(t_info *)	info: pointer to struct which contains the conversion
**					information.
**
** Returns:
** 		(void) 		None.
*/

void	p_convert(va_list ap, t_info *info)
{
	unsigned long	addr;
	char			*str_nb;
	char			*str;

	addr = va_arg(ap, unsigned long);
	str_nb = ft_ultoa_hex(addr);
	str = create_array_p(str_nb, info);
	if (str == NULL)
	{
		info->err = 1;
		return ;
	}
	info->return_val = ft_strlen(str);
	fill_addr(str, str_nb, info);
	ft_putstr_fd(str, 1);
	free(str_nb);
	free(str);
}

/*
** The create_array_p function allocates exactly enough memory for the string.
** It also fills it with spaces using the ft_memset function from libft.
**
** Arguments:
**		(char *)	str_nb: the number in a string (result of ft_ultoa_hex).
**		(t_info *)	info: pointer to struct which contains the conversion
**					information.
**
** Returns:
**		(char *) 	str: string which is filled with spaces.
*/

char	*create_array_p(char *str_nb, t_info *info)
{
	int		len_str;
	char	*str;

	len_str = ft_strlen(str_nb) + 2;
	if (len_str < info->width)
		len_str = info->width;
	str = (char *)malloc(sizeof(char) * len_str + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, ' ', (size_t)len_str);
	*(str + len_str) = '\0';
	return (str);
}

/*
** The fill_addr function fills the string with the address.
** It also add 0x at the beginning of the string.
**
** Arguments:
**		(char *)	str: the string to be filled.
**		(char *)	str_nb: the number in a string (result from ft_ultoa_hex).
**		(t_info *)	info: pointer to struct which contains the conversion
**					information.
**
** Returns:
**		(void) 		None.
*/

void	fill_addr(char *str, char *str_nb, t_info *info)
{
	int i;
	int j;
	int	len_str;

	i = 0;
	j = 0;
	len_str = ft_strlen(str);
	if (info->dash == 0)
		i = len_str - (int)ft_strlen(str_nb) - 2;
	*(str + i) = '0';
	*(str + i + 1) = 'x';
	i = i + 2;
	while (*(str_nb + j) != '\0')
	{
		*(str + i) = *(str_nb + j);
		i++;
		j++;
	}
}
