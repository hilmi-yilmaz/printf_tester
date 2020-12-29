/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/18 14:35:20 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/27 15:42:04 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		step;
	int		read_val;
	int		count;
	t_info	info;

	va_start(ap, fmt);
	i = 0;
	count = 0;
	while (*(fmt + i) != '\0')
	{
		if (*(fmt + i) == '%')
		{
			step = set_info(fmt + i + 1, &info, ap);
			if (step == -1)
				return (-1);
			i += step;
			conversion(ap, &info);
			if (info.err == 1)
				return (-1);
			count += info.return_val;
		}
		else
		{
			read_val = write(1, fmt + i, 1);
			if (read_val == -1)
				return (-1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
