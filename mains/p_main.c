/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_main.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 22:32:26 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/03/11 10:32:42 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *fmt, ...);

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
	res_ft = ft_printf("%p\n", &a);//1 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", &a);
	res_ft = ft_printf("%.p\n", &a);//2 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", &a);
	res_ft = ft_printf("%20p\n", &a);//3 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", &a);
	res_ft = ft_printf("%20.p\n", &a);//4 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", &a);
	res_ft = ft_printf("%-20p\n", &a);//5 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", &a);
	res_ft = ft_printf("%-20.p\n", &a);//6 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", &a);
	res_ft = ft_printf("%10p\n", &a);//7 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", &a);
	res_ft = ft_printf("%10.p\n", &a);//8 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", &a);
	res_ft = ft_printf("%-10p\n", &a);//9 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", &a);
	res_ft = ft_printf("%-10.p\n", &a);//10 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", &a);
	res_ft = ft_printf("%14p\n", &a);//11 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", &a);
	res_ft = ft_printf("%14.p\n", &a);//12 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", &a);
	res_ft = ft_printf("%-14p\n", &a);//13 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", &a);
	res_ft = ft_printf("%-14.p\n", &a);//14 -- int a = 0;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	/*
	** Testing with variable b
	*/

    res_c = fprintf(fd_c_print, "%p\n", &b);
	res_ft = ft_printf("%p\n", &b);//15 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", &b);
	res_ft = ft_printf("%.p\n", &b);//16 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", &b);
	res_ft = ft_printf("%20p\n", &b);//17 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", &b);
	res_ft = ft_printf("%20.p\n", &b);//18 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", &b);
	res_ft = ft_printf("%-20p\n", &b);//19 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", &b);
	res_ft = ft_printf("%-20.p\n", &b);//20 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", &b);
	res_ft = ft_printf("%10p\n", &b);//21 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", &b);
	res_ft = ft_printf("%10.p\n", &b);//22 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", &b);
	res_ft = ft_printf("%-10p\n", &b);//23 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", &b);
	res_ft = ft_printf("%-10.p\n", &b);//24 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", &b);
	res_ft = ft_printf("%14p\n", &b);//25 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", &b);
	res_ft = ft_printf("%14.p\n", &b);//26 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", &b);
	res_ft = ft_printf("%-14p\n", &b);//27 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", &b);
	res_ft = ft_printf("%-14.p\n", &b);//28 -- b = 'A';
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	/*
	** Testing with variable c
	*/

    res_c = fprintf(fd_c_print, "%p\n", c);
	res_ft = ft_printf("%p\n", c);//29 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", c);
	res_ft = ft_printf("%.p\n", c);//30 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", c);
	res_ft = ft_printf("%20p\n", c);//31 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", c);
	res_ft = ft_printf("%20.p\n", c);//32 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", c);
	res_ft = ft_printf("%-20p\n", c);//33 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", c);
	res_ft = ft_printf("%-20.p\n", c);//34 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", c);
	res_ft = ft_printf("%10p\n", c);//35 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", c);
	res_ft = ft_printf("%10.p\n", c);//36 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", c);
	res_ft = ft_printf("%-10p\n", c);//37 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", c);
	res_ft = ft_printf("%-10.p\n", c);//38 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", c);
	res_ft = ft_printf("%14p\n", c);//39 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", c);
	res_ft = ft_printf("%14.p\n", c);//40 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", c);
	res_ft = ft_printf("%-14p\n", c);//41 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", c);
	res_ft = ft_printf("%-14.p\n", c);//42 -- c = "hilmi";
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	/*
	** Testing with variable d
	*/

    res_c = fprintf(fd_c_print, "%p\n", d);
	res_ft = ft_printf("%p\n", d);//43 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", d);
	res_ft = ft_printf("%.p\n", d);//44 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", d);
	res_ft = ft_printf("%20p\n", d);//45 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", d);
	res_ft = ft_printf("%20.p\n", d);//46 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", d);
	res_ft = ft_printf("%-20p\n", d);//47 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", d);
	res_ft = ft_printf("%-20.p\n", d);//48 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", d);
	res_ft = ft_printf("%10p\n", d);//49 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", d);
	res_ft = ft_printf("%10.p\n", d);//50 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", d);
	res_ft = ft_printf("%-10p\n", d);//51 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", d);
	res_ft = ft_printf("%-10.p\n", d);//52 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", d);
	res_ft = ft_printf("%14p\n", d);//53 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", d);
	res_ft = ft_printf("%14.p\n", d);//54 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", d);
	res_ft = ft_printf("%-14p\n", d);//55 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", d);
	res_ft = ft_printf("%-14.p\n", d);//56 -- d = malloc(sizeof(char) * 10);
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	/*
	** Testing with variable e
	*/

    res_c = fprintf(fd_c_print, "%p\n", e);
	res_ft = ft_printf("%p\n", e);//57 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%.p\n", e);
	res_ft = ft_printf("%.p\n", e);//58 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%20p\n", e);
	res_ft = ft_printf("%20p\n", e);//59 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%20.p\n", e);
	res_ft = ft_printf("%20.p\n", e);//60 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%-20p\n", e);
	res_ft = ft_printf("%-20p\n", e);//61 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
    res_c = fprintf(fd_c_print, "%-20.p\n", e);
	res_ft = ft_printf("%-20.p\n", e);//62 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);
	
	res_c = fprintf(fd_c_print, "%10p\n", e);
	res_ft = ft_printf("%10p\n", e);//63 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%10.p\n", e);
	res_ft = ft_printf("%10.p\n", e);//64 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10p\n", e);
	res_ft = ft_printf("%-10p\n", e);//65 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-10.p\n", e);
	res_ft = ft_printf("%-10.p\n", e);//66 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14p\n", e);
	res_ft = ft_printf("%14p\n", e);//67 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

    res_c = fprintf(fd_c_print, "%14.p\n", e);
	res_ft = ft_printf("%14.p\n", e);//68 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14p\n", e);
	res_ft = ft_printf("%-14p\n", e);//69 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);

	res_c = fprintf(fd_c_print, "%-14.p\n", e);
	res_ft = ft_printf("%-14.p\n", e);//70 -- e = NULL;
	fprintf(fd_c, "%d\n", res_c);
	fprintf(fd_ft, "%d\n", res_ft);


    free (d);
    return (0);
}
