/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_convert.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/24 18:36:16 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/27 13:56:41 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
** The c_convert function prints the c-conversion.
** It uses ft_putstr_fd from libft.
** It also uses the below  function.
**
** Arguments:
**		(va_list)	ap: the argument list which contains the unnamed arguments.
**		(t_info *)	info: pointer to struct which contains the conversion
**					information.
**
** Returns:
** 		(void) 		None.
*/

void	c_convert(va_list ap, t_info *info)
{
	unsigned char	c;
	char			*str;
	int				i;
	int				len_str;

	i = 0;
	c = va_arg(ap, int);
	str = create_array_c(info);
	len_str = (int)ft_strlen(str);
	if (str == NULL)
	{
		info->err = 1;
		return ;
	}
	while (*(str + i) != '\0')
	{
		*(str + i) = ' ';
		i++;
	}
	if (info->dash == 0)
		*(str + len_str - 1) = c;
	else
		*(str + 0) = c;
	ft_putstr_fd(str, 1);
	free(str);
}

/*
** The create_array_c function allocates exactly enough memory for the string.
**
** Arguments:
**		(t_info *)	info: pointer to struct which contains the conversion
**					information.
**
** Returns:
**		(char *) 	str: string which contains a \0 and garbage value.
*/

char	*create_array_c(t_info *info)
{
	int		len_str;
	char	*str;

	if (info->width == 0)
		len_str = 1;
	else
		len_str = info->width;
	str = (char *)malloc(sizeof(char) * len_str + 1);
	if (str == NULL)
	{
		info->err = 1;
		return (NULL);
	}
	*(str + len_str) = '\0';
	info->return_val = ft_strlen(str);
	return (str);
}
