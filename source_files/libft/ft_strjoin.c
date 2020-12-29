/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 13:34:16 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/17 17:23:50 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*fill_malloc(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*joined_str;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = (char*)malloc(s1_len + s2_len + 1);
	if (joined_str == NULL)
		return (NULL);
	while (i < (s1_len + s2_len))
	{
		if (i < s1_len)
			*(joined_str + i) = *(s1 + i);
		else
			*(joined_str + i) = *(s2 + i - s1_len);
		i++;
	}
	*(joined_str + i) = '\0';
	return (joined_str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	else
		return (fill_malloc(s1, s2));
}
