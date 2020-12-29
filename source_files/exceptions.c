/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exceptions.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/25 11:19:08 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/27 12:35:24 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The exceptions functions sets some exceptions as given in the manpage.
**
**		(t_info *)		info: pointer to struct which contains the conversion
**						information.
**
** Returns:
**		(void)			None.
*/

void	exceptions(t_info *info)
{
	if (info->dash == 1)
		info->zero = 0;
	if (info->prec != -1)
		info->zero = 0;
	if (info->width < 0)
	{
		info->width = info->width * -1;
		info->dash = 1;
	}
}
