/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_ft_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/01 17:17:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/01/01 23:09:12 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../source_files/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	FILE *fd;
	int res;

	fd = fopen("logs/results/s_ft_return_val", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}
	
	/*
	** Testing with single parameters
	*/

	res = ft_printf("%s\n", "codam");//1
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%10s\n", "codam");//2
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-10s\n", "codam");//3
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3s\n", "codam");//4
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3s\n", "codam");//5
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5s\n", "codam");//6
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5s\n", "codam");//7
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.3s\n", "codam");//8
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.3s\n", "codam");//9
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.7s\n", "codam");//10
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.7s\n", "codam");//11
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.5s\n", "codam");//12
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.5s\n", "codam");//13
	fprintf(fd, "%d\n", res);

	/*
	** Testing with length string longer than precesion and width
	*/

	res = ft_printf("%2.4s|\n", "codam");
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%-2.4s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.2s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-4.2s|\n", "codam");
	fprintf(fd, "%d\n", res);

	/*
	** Testing with length string in the middle of precesion and width
	*/

	res = ft_printf("%2.5s|\n", "cod");
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%-2.5s|\n", "cod");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.2s|\n", "cod");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.2s|\n", "cod");
	fprintf(fd, "%d\n", res);

	/*
	** Testing with length string smallest of precesion and width
	*/

	res = ft_printf("%4.5s|\n", "cod");
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%-4.5s|\n", "cod");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.4s|\n", "cod");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.4s|\n", "cod");
	fprintf(fd, "%d\n", res);

	/*
	** Testing with equal length: 
	** - string length = precision
	** - string length = width
	** - width = precision
	*/

	res = ft_printf("%4.4s|\n", "codam");
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%-4.4s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.6s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-6.6s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.5s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.5s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.5s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-6.5s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.2s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.2s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.6s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.6s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.5s|\n", "codam");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.5s|\n", "codam");
	fprintf(fd, "%d\n", res);

	/*
	** Test with empty string
	*/

	res = ft_printf("%-s|\n", "");
	fprintf(fd, "%d\n", res);	
	res = ft_printf("%s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%10s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-10s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.3s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.3s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.7s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.7s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.5s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.5s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.5s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.5s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.2s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.2s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5.s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.s|\n", "");
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-.s|\n", "");
	fprintf(fd, "%d\n", res);

	return (0);
}
