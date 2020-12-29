/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper_str_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 14:00:02 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/26 14:05:00 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_toupper_str(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		*(str + i) = ft_toupper(*(str + i));
		i++;
	}
}
