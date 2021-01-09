/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ft_C_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/02 12:19:16 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/09 10:21:30 by hyilmaz       ########   odam.nl         */
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
	char	b;
	char	*c;
	char	*d;
	char	*e;

	fd = fopen("logs/results/p_ft_C_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}
	
	a = 0;
	b = 'A';
	c = "hilmi";
	d = malloc(sizeof(char) * 10);
	e = NULL;

	/*
	** Testing with variable a
	*/

	res_c = printf("|%p|\n", &a);
	fflush(stdout);
	res_ft = ft_printf("|%p|\n", &a);//1
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%20p|\n", &a);
	fflush(stdout);
	res_ft = ft_printf("|%20p|\n", &a);//2
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-20p|\n", &a);
	fflush(stdout);
	res_ft = ft_printf("|%-20p|\n", &a);//3
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%10p|\n", &a);
	fflush(stdout);
	res_ft = ft_printf("|%10p|\n", &a);//4
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-10p|\n", &a);
	fflush(stdout);
	res_ft = ft_printf("|%-10p|\n", &a);//5
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 20, &a);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 20, &a);//6
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -20, &a);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -20, &a);//7
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 10, &a);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 10, &a);//8
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -10, &a);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -10, &a);//9
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 15, &a);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 15, &a);//10
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -15, &a);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -15, &a);//11
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	/*
	** Testing with variable b
	*/

	res_c = printf("|%p|\n", &b);
	fflush(stdout);
	res_ft = ft_printf("|%p|\n", &b);//12
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%20p|\n", &b);
	fflush(stdout);
	res_ft = ft_printf("|%20p|\n", &b);//13
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-20p|\n", &b);
	fflush(stdout);
	res_ft = ft_printf("|%-20p|\n", &b);//14
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%10p|\n", &b);
	fflush(stdout);
	res_ft = ft_printf("|%10p|\n", &b);//15
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-10p|\n", &b);
	fflush(stdout);
	res_ft = ft_printf("|%-10p|\n", &b);//16
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 20, &b);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 20, &b);//17
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -20, &b);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -20, &b);//18
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 10, &b);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 10, &b);//19
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -10, &b);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -10, &b);//20
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 15, &b);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 15, &b);//21
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -15, &b);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -15, &b);//22
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	/*
	** Testing with variable c
	*/

	res_c = printf("|%p|\n", c);
	fflush(stdout);
	res_ft = ft_printf("|%p|\n", c);//23
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%20p|\n", c);
	fflush(stdout);
	res_ft = ft_printf("|%20p|\n", c);//24
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-20p|\n", c);
	fflush(stdout);
	res_ft = ft_printf("|%-20p|\n", c);//25
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%10p|\n", c);
	fflush(stdout);
	res_ft = ft_printf("|%10p|\n", c);//26
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-10p|\n", c);
	fflush(stdout);
	res_ft = ft_printf("|%-10p|\n", c);//27
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 20, c);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 20, c);//28
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -20, c);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -20, c);//29
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 10, c);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 10, c);//30
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -10, c);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -10, c);//31
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 15, c);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 15, c);//32
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -15, c);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -15, c);//33
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	/*
	** Testing with variable d
	*/

	res_c = printf("|%p|\n", d);
	fflush(stdout);
	res_ft = ft_printf("|%p|\n", d);//34
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);

	res_c = printf("|%20p|\n", d);
	fflush(stdout);
	res_ft = ft_printf("|%20p|\n", d);//35
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-20p|\n", d);
	fflush(stdout);
	res_ft = ft_printf("|%-20p|\n", d);//36
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%10p|\n", d);
	fflush(stdout);
	res_ft = ft_printf("|%10p|\n", d);//37
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-10p|\n", d);
	fflush(stdout);
	res_ft = ft_printf("|%-10p|\n", d);//38
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 20, d);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 20, d);//39
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -20, d);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -20, d);//40
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 10, d);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 10, d);//41
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -10, d);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -10, d);//42
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 15, d);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 15, d);//43
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -15, d);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -15, d);//44
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	/*
	** Testing with variable e
	*/

	res_c = printf("|%p|\n", e);
	fflush(stdout);
	res_ft = ft_printf("|%p|\n", e);//45
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);

	res_c = printf("|%20p|\n", e);
	fflush(stdout);
	res_ft = ft_printf("|%20p|\n", e);//46
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-20p|\n", e);
	fflush(stdout);
	res_ft = ft_printf("|%-20p|\n", e);//47
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%10p|\n", e);
	fflush(stdout);
	res_ft = ft_printf("|%10p|\n", e);//48
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%-10p|\n", e);
	fflush(stdout);
	res_ft = ft_printf("|%-10p|\n", e);//49
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 20, e);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 20, e);//50
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -20, e);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -20, e);//51
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 10, e);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 10, e);//52
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -10, e);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -10, e);//53
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", 15, e);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", 15, e);//54
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	res_c = printf("|%*p|\n", -15, e);
	fflush(stdout);
	res_ft = ft_printf("|%*p|\n", -15, e);//55
	printf("%d\n", res_c);
	fflush(stdout);
	printf("%d\n\n", res_ft);
	fflush(stdout);
	
	free(d);
	
	return (0);
}
