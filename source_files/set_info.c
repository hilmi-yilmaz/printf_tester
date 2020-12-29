/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_info.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 10:32:28 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/27 13:26:47 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
** The set_info function sets the information for the conversions.
** It start by giving default values.
** prec = -1 means no precision given.
** It also handles some exceptions, see exceptions.c.
**
** Arguments:
**		(const char *)	str_conv: the start of the conversion string.
**		(t_info *)		info: pointer to struct which contains the conversion
**						information.
**		(va_list)		ap: The argument list which contains the unnamed
**						arguments.
**
** Returns:
**		(int) 			step: the step taken.
**						If memory allocation fails, returns -1.
*/

int		set_info(const char *str_conv, t_info *info, va_list ap)
{
	int	step;

	step = 0;
	info->dash = 0;
	info->zero = 0;
	info->prec = -1;
	info->width = 0;
	info->err = 0;
	info->return_val = 0;
	info->spec = '\0';
	step += set_flags(str_conv, info);
	step += set_width(str_conv + step, info, ap);
	if (info->err == 1)
		return (-1);
	step += set_prec(str_conv + step, info, ap);
	if (info->err == 1)
		return (-1);
	step += set_spec(str_conv + step, info);
	exceptions(info);
	return (step);
}

/*
** The set_flags function sets the '-' and '0' flags.
**
** Arguments:
**		(const char *)	str_conv: the start of the conversion string.
**		(t_info *)		info: pointer to struct which contains the conversion
**						information.
**
** Returns:
**		(int) 			i: the steps taken
*/

int		set_flags(const char *str_conv, t_info *info)
{
	int i;

	i = 0;
	while (*(str_conv + i) == '-' || *(str_conv + i) == '0')
	{
		if (*(str_conv + i) == '-')
			info->dash = 1;
		if (*(str_conv + i) == '0')
			info->zero = 1;
		i++;
	}
	return (i);
}

/*
** The set_width function sets the field width.
** It allocates memory and creates a string which contains the string
** representation of an integer. Then, ft_atoi is used to convert to integer.
**
** Arguments:
**		(const char *)	str_conv: the start of the conversion string.
**		(t_info *)		info: pointer to struct which contains the conversion
**						information.
**		(va_list)		ap: The argument list which contains the unnamed
**						arguments.
**
** Returns:
**		(int) 	i: the steps taken.
**				If memory allocation fails, return -1.
*/

int		set_width(const char *str_conv, t_info *info, va_list ap)
{
	int		i;
	char	*width;

	i = 0;
	if (*(str_conv + i) == '*')
	{
		info->width = va_arg(ap, int);
		return (1);
	}
	while (ft_isdigit(*(str_conv + i)) > 0)
		i++;
	width = ft_substr(str_conv, 0, i);
	if (width == NULL)
	{
		info->err = 1;
		return (-1);
	}
	info->width = ft_atoi(width);
	free(width);
	return (i);
}

/*
** The set_prec function sets the precision.
** If the precision is gives only as a dot, the precision is zero.
**
** Arguments:
**		(const char *)	str_conv: the start of the conversion string.
**		(t_info *)		info: pointer to struct which contains the conversion
**						information.
**		(va_list)		ap: The argument list which contains the unnamed
**						arguments.
**
** Returns:
**		(int) 			i + j: the steps taken.
**						If memory allocation fails, return -1;
**						If no precision specified, return 0.
*/

int		set_prec(const char *str_conv, t_info *info, va_list ap)
{
	int		i;
	int		j;
	char	*prec;

	i = 0;
	j = 0;
	if (*(str_conv + j) == '.')
		j++;
	else
		return (0);
	if (*(str_conv + i + j) == '*')
	{
		info->prec = va_arg(ap, int);
		return (2);
	}
	while (ft_isdigit(*(str_conv + j + i)) > 0)
		i++;
	prec = ft_substr(str_conv + j, 0, i);
	if (prec == NULL)
	{
		info->err = 1;
		return (-1);
	}
	info->prec = ft_atoi(prec);
	free(prec);
	return (i + j);
}

/*
** The set_spec function sets the conversion specifier.
**
** Arguments:
**		(const char *)	str_conv: the start of the conversion string.
**		(t_info *)		info: pointer to struct which contains the conversion
**						information.
**		(va_list)		ap: The argument list which contains the unnamed
**						arguments.
**
** Returns:
**		(int) 			1, because it expects only 1 specifier.
*/

int		set_spec(const char *str_conv, t_info *info)
{
	info->spec = *(str_conv + 0);
	return (1);
}
