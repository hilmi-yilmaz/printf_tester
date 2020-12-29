/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 17:03:24 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/14 19:11:16 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	size_t	i;
	char	*mapped_str;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	mapped_str = (char*)malloc(len_s + 1);
	if (mapped_str == NULL)
		return (NULL);
	while (i < len_s)
	{
		*(mapped_str + i) = (*f)(i, *(s + i));
		i++;
	}
	*(mapped_str + i) = '\0';
	return (mapped_str);
}
