/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_main.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 10:53:11 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/30 12:13:04 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../source_files/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	FILE *fd;
	int res;

	fd = fopen("logs/results/return_val_id_ft", "a+");
	if (fd == NULL)
	{
		printf("Couldn't open file\n");
		exit(1);
	}

	/*
	** Printing positive numbers with dash = 0
	*/

	res = ft_printf("%7.5d", 123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.2d", 123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.3d", 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.4d", 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.7d", 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.7d", 12345);
	fprintf(fd, "%d\n", res);

	/*
	** Printing negative numbers with dash = 0
	*/

	res = ft_printf("%7.5d", -123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.2d", -123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.3d", -12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.4d", -12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.9d", -12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.9d", -12345);
	fprintf(fd, "%d\n", res);

	/*
	** Printing with equal parameters with dash = 0
	** The parameters are: field width, precision and number length.
	** The number length includes the '-' sign. 
	** Thus -123 has length 4.
	*/
	
	res = ft_printf("%7.7d", 123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.2d", 123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.3d", 1234);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.4d", 1234);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.2d", 12);
	fprintf(fd, "%d\n", res);

	res = ft_printf("%7.7d", -123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.2d", -123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5.3d", -1234);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.5d", -1234);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.3d", -12);
	fprintf(fd, "%d\n", res);
	
	/*
	** Printing with 0 parameters with dash = 0
	*/

	res = ft_printf("%0.5d", 123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.0d", 123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.3d", 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.0d", 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.0d", 0);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.d", 0);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.7d", 0);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.0d", 0);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.d", 0);
	fprintf(fd, "%d\n", res);

	/*
	** Print extreme values dash = 0
	*/

	res = ft_printf("%15.5d", 2147483647);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.15d", 2147483647);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.5d", -2147483647);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.15d", -2147483647);
	fprintf(fd, "%d\n", res);

	/*
	** Printing with extra zeros dash = 0
	*/

	res = ft_printf("%d", 001);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%d", -001);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.5d", 001);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.15d", -001);
	fprintf(fd, "%d\n", res);

	/*
	** Printing with '+' with dash = 0
	*/

	res = ft_printf("%d", +123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%d", +0);
	fprintf(fd, "%d\n", res);

	/*
	** Printing with * with dash = 0 and dash = 1 
	*/

	res = ft_printf("%*.5d", 7, 123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.*d", 2, 123);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*d", 4, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*d", -4, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*d", -4, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*d", -8, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*d", -8, 3, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*d", -4, -3, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*d", -4, -3, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*d", -8, -3, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*d", -8, -3, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*d", -4, -10, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*d", -4, -10, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*.*d", -8, -10, 12345);
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*.*d", -8, -10, 12345);
	fprintf(fd, "%d\n", res);

	return (0);
}
