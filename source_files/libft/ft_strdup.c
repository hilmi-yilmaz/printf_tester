/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 15:16:24 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/17 15:37:14 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*copy;
	size_t	i;

	i = 0;
	len_s1 = ft_strlen(s1);
	copy = (char*)malloc((len_s1 + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (i < len_s1)
	{
		*(copy + i) = *(s1 + i);
		i++;
	}
	*(copy + i) = '\0';
	return (copy);
}
