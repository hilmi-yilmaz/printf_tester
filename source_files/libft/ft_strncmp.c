/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 15:02:45 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/17 15:32:42 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_unsig;
	unsigned char	*s2_unsig;

	i = 0;
	s1_unsig = (unsigned char *)s1;
	s2_unsig = (unsigned char *)s2;
	while (i < n && (*(s1_unsig + i) != '\0' || *(s2_unsig + i) != '\0'))
	{
		if (*(s1_unsig + i) != *(s2_unsig + i))
			return (*(s1_unsig + i) - *(s2_unsig + i));
		i++;
	}
	return (0);
}
