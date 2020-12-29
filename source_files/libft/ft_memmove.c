/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:05:02 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/17 15:13:43 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	non_overlap_loop(unsigned char *ptr_dst,
						const unsigned char *ptr_src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(ptr_dst + i) = *(ptr_src + i);
		i++;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	ptr_src = src;
	ptr_dst = dst;
	if (dst < src)
	{
		non_overlap_loop(ptr_dst, ptr_src, len);
	}
	else
	{
		while (i < len)
		{
			*(ptr_dst + len - i - 1) = *(ptr_src + len - i - 1);
			i++;
		}
	}
	return ((void*)dst);
}
