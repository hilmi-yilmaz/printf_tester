/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 12:29:31 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/14 17:42:51 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int set_i;

	i = 0;
	set_i = -1;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			set_i = i;
		i++;
	}
	if (set_i >= 0)
		return ((char*)s + set_i);
	if (c == '\0')
		return ((char*)s + i);
	return (NULL);
}
