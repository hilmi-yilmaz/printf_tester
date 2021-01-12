/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 22:32:26 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/12 12:27:08 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	
	FILE	*fd_c;
    FILE    *fd_ft;
    FILE    *fd_c_print;
	int		res_c;
	int		res_ft;

	int		a;
	char	b;
	char	*c;
	char	*d;
	char	*e;

	fd_c = fopen("logs/results/p_C_return_val", "a+");
	if (fd_c == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}

	fd_ft = fopen("logs/results/p_ft_return_val", "a+");
	if (fd_ft == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}
	
    fd_c_print = fopen("logs/results/p_C_printed", "a+");
	if (fd_c_print == NULL)
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

    res_c = fprintf(fd_c_print, "%p\n", &a);
	res_ft = ft_printf("%p\n", &a);//1
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", &a);
	res_ft = ft_printf("%.p\n", &a);//2
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", &a);
	res_ft = ft_printf("%20p\n", &a);//3
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", &a);
	res_ft = ft_printf("%20.p\n", &a);//4
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", &a);
	res_ft = ft_printf("%-20p\n", &a);//5
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", &a);
	res_ft = ft_printf("%-20.p\n", &a);//6
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", &a);
	res_ft = ft_printf("%10p\n", &a);//7
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", &a);
	res_ft = ft_printf("%10.p\n", &a);//8
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", &a);
	res_ft = ft_printf("%-10p\n", &a);//9
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", &a);
	res_ft = ft_printf("%-10.p\n", &a);//10
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", &a);
	res_ft = ft_printf("%14p\n", &a);//11
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", &a);
	res_ft = ft_printf("%14.p\n", &a);//12
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", &a);
	res_ft = ft_printf("%-14p\n", &a);//13
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", &a);
	res_ft = ft_printf("%-14.p\n", &a);//14
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	/*
	** Testing with variable b
	*/

    res_c = fprintf(fd_c_print, "%p\n", &b);
	res_ft = ft_printf("%p\n", &b);//15
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", &b);
	res_ft = ft_printf("%.p\n", &b);//16
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", &b);
	res_ft = ft_printf("%20p\n", &b);//17
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", &b);
	res_ft = ft_printf("%20.p\n", &b);//18
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", &b);
	res_ft = ft_printf("%-20p\n", &b);//19
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", &b);
	res_ft = ft_printf("%-20.p\n", &b);//20
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", &b);
	res_ft = ft_printf("%10p\n", &b);//21
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", &b);
	res_ft = ft_printf("%10.p\n", &b);//22
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", &b);
	res_ft = ft_printf("%-10p\n", &b);//23
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", &b);
	res_ft = ft_printf("%-10.p\n", &b);//24
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", &b);
	res_ft = ft_printf("%14p\n", &b);//25
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", &b);
	res_ft = ft_printf("%14.p\n", &b);//26
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", &b);
	res_ft = ft_printf("%-14p\n", &b);//27
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", &b);
	res_ft = ft_printf("%-14.p\n", &b);//28
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	/*
	** Testing with variable c
	*/

    res_c = fprintf(fd_c_print, "%p\n", c);
	res_ft = ft_printf("%p\n", c);//29
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", c);
	res_ft = ft_printf("%.p\n", c);//30
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", c);
	res_ft = ft_printf("%20p\n", c);//31
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", c);
	res_ft = ft_printf("%20.p\n", c);//32
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", c);
	res_ft = ft_printf("%-20p\n", c);//33
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", c);
	res_ft = ft_printf("%-20.p\n", c);//34
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", c);
	res_ft = ft_printf("%10p\n", c);//35
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", c);
	res_ft = ft_printf("%10.p\n", c);//36
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", c);
	res_ft = ft_printf("%-10p\n", c);//37
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", c);
	res_ft = ft_printf("%-10.p\n", c);//38
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", c);
	res_ft = ft_printf("%14p\n", c);//39
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", c);
	res_ft = ft_printf("%14.p\n", c);//40
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", c);
	res_ft = ft_printf("%-14p\n", c);//41
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", c);
	res_ft = ft_printf("%-14.p\n", c);//42
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	/*
	** Testing with variable d
	*/

    res_c = fprintf(fd_c_print, "%p\n", d);
	res_ft = ft_printf("%p\n", d);//43
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", d);
	res_ft = ft_printf("%.p\n", d);//44
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", d);
	res_ft = ft_printf("%20p\n", d);//45
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", d);
	res_ft = ft_printf("%20.p\n", d);//46
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", d);
	res_ft = ft_printf("%-20p\n", d);//47
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", d);
	res_ft = ft_printf("%-20.p\n", d);//48
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", d);
	res_ft = ft_printf("%10p\n", d);//49
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", d);
	res_ft = ft_printf("%10.p\n", d);//50
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", d);
	res_ft = ft_printf("%-10p\n", d);//51
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", d);
	res_ft = ft_printf("%-10.p\n", d);//52
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", d);
	res_ft = ft_printf("%14p\n", d);//53
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", d);
	res_ft = ft_printf("%14.p\n", d);//54
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", d);
	res_ft = ft_printf("%-14p\n", d);//55
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", d);
	res_ft = ft_printf("%-14.p\n", d);//56
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	/*
	** Testing with variable e
	*/

    res_c = fprintf(fd_c_print, "%p\n", e);
	res_ft = ft_printf("%p\n", e);//57
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", e);
	res_ft = ft_printf("%.p\n", e);//58
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", e);
	res_ft = ft_printf("%20p\n", e);//59
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", e);
	res_ft = ft_printf("%20.p\n", e);//60
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", e);
	res_ft = ft_printf("%-20p\n", e);//61
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", e);
	res_ft = ft_printf("%-20.p\n", e);//62
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", e);
	res_ft = ft_printf("%10p\n", e);//63
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", e);
	res_ft = ft_printf("%10.p\n", e);//64
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", e);
	res_ft = ft_printf("%-10p\n", e);//65
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", e);
	res_ft = ft_printf("%-10.p\n", e);//66
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", e);
	res_ft = ft_printf("%14p\n", e);//67
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", e);
	res_ft = ft_printf("%14.p\n", e);//68
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", e);
	res_ft = ft_printf("%-14p\n", e);//69
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", e);
	res_ft = ft_printf("%-14.p\n", e);//70
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);


    free (d);
    return (0);
}
