/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 22:32:26 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/11 22:32:28 by hyilmaz       ########   odam.nl         */
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

    res_c = fprintf(fd_c_print, "%.0p\n", &a);
	res_ft = ft_printf("%.0p\n", &a);//3
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.20p\n", &a);
	res_ft = ft_printf("%.20p\n", &a);//4
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.10p\n", &a);
	res_ft = ft_printf("%.10p\n", &a);//5
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.14p\n", &a);
	res_ft = ft_printf("%.14p\n", &a);//6
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", &a);
	res_ft = ft_printf("%20p\n", &a);//7
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", &a);
	res_ft = ft_printf("%-20p\n", &a);//8
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", &a);
	res_ft = ft_printf("%10p\n", &a);//9
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", &a);
	res_ft = ft_printf("%-10p\n", &a);//10
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", &a);
	res_ft = ft_printf("%14p\n", &a);//11
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", &a);
	res_ft = ft_printf("%-14p\n", &a);//12
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    free (d);
    return (0);
}
