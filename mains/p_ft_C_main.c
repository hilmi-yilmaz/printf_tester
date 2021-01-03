/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ft_C_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/02 12:19:16 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/03 11:14:42 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../source_files/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	
	FILE	*fd;
	int		res_c;
	int		res_ft;

	int		a;
	int		b;
	char	c;
	char	d;
	char	*e;
	char	*f;

	fd = fopen("logs/results/p_ft_C_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}
	
	a = 0;
	b = 1234;
	c = 'A';
	d = ']';
	e = "hilmi";
	f = malloc(sizeof(char) * 10);

	res_c = printf("%p\n", &a);
	res_ft = ft_printf("%p\n", &a);//1
	printf("%d\n", res_c);
	printf("%d\n\n", res_ft);
	
	res_c = printf("%p\n", &b);
	res_ft = ft_printf("%p\n", &b);//2
	printf("%d\n", res_c);
	printf("%d\n\n", res_ft);
	
	res_c = printf("%p\n", &c);
	res_ft = ft_printf("%p\n", &c);//3
	printf("%d\n", res_c);
	printf("%d\n\n", res_ft);
	
	res_c = printf("%p\n", &d);
	res_ft = ft_printf("%p\n", &d);//4
	printf("%d\n", res_c);
	printf("%d\n\n", res_ft);

	res_c = printf("%p\n", &e);
	res_ft = ft_printf("%p\n", &e);//5
	printf("%d\n", res_c);
	printf("%d\n\n", res_ft);

	res_c = printf("%p\n", &f);
	res_ft = ft_printf("%p\n", &f);//6
	printf("%d\n", res_c);
	printf("%d\n\n", res_ft);

	free(f);
	
	return (0);
}
