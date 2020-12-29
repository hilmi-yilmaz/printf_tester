/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 17:58:32 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/18 19:34:56 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			split_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c && (*(s + i + 1) == c || *(s + i + 1) == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int			skip_delims(char *s, char c)
{
	int i;

	i = 0;
	while (*(s + i) == c)
		i++;
	return (i);
}

static char			**free_array(char **array, int i)
{
	int c;

	c = 0;
	while (c < i)
	{
		free(*(array + c));
		c++;
	}
	free(array);
	return (NULL);
}

static char			**fill_array(char **array, char *s, char c, int elements)
{
	int i;
	int	len_word;

	i = 0;
	len_word = 0;
	while (i < elements - 1)
	{
		s = s + len_word;
		s = s + skip_delims(s, c);
		len_word = 0;
		while (*(s + len_word) != c && *(s + len_word) != '\0')
			len_word++;
		*(array + i) = ft_substr(s, 0, len_word);
		if (*(array + i) == NULL)
			return (free_array(array, i));
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char				**ft_split(char const *s, char c)
{
	int		elements;
	char	**array;
	char	*typecasted_s;

	if (s == NULL)
		return (NULL);
	typecasted_s = (char*)s;
	elements = split_count(typecasted_s, c) + 1;
	array = (char**)malloc(sizeof(char*) * elements);
	if (array == NULL)
		return (NULL);
	array = fill_array(array, typecasted_s, c, elements);
	return (array);
}
