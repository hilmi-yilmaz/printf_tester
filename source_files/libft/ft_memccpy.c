/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 18:27:30 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/14 17:31:51 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	i = 0;
	ptr_dest = dest;
	ptr_src = src;
	while (i < n)
	{
		*(ptr_dest + i) = *(ptr_src + i);
		if (*(ptr_src + i) == (unsigned char)c)
		{
			return ((void*)ptr_dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
